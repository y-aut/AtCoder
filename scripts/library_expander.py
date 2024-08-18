#!/usr/bin/env python3

import re
import argparse
from logging import Logger, basicConfig, getLogger
from os import getenv
from pathlib import Path
from typing import List, Set, Optional


logger = getLogger(__name__)  # type: Logger


class Expander:
    library_include = re.compile(r'#include\s*[<"]library/(([^/]+)/.*\.hpp)[>"]\s*')
    inner_include = re.compile(r'#include\s*[<"](.*\.hpp)[>"]\s*')

    def is_ignored_line(self, line) -> bool:
        if line.strip() == "#pragma once":
            return True
        if line.strip().startswith('//'):
            return True
        return False

    def __init__(self, lib_path: Path):
        self.lib_path = lib_path

    included = set()    # type: Set[Path]

    def find_library_path(self, file_path: str) -> Path:
        path = lib_path / file_path
        if path.exists():
            return path
        logger.error('cannot find: {}'.format(file_path))
        raise FileNotFoundError()

    def find_inner_file(self, file_path: str, include_path: List[Path]) -> Optional[Path]:
        for include in include_path[::-1]:
            path = include / file_path
            if path.exists():
                return path
        logger.warning('cannot find: {}'.format(file_path))
        return None

    def expand_lib(self, file_path: Path, include_path: List[Path]) -> List[str]:
        if file_path in self.included:
            logger.info('already included: {}'.format(file_path.name))
            return []
        self.included.add(file_path)
        logger.info('include: {}'.format(file_path.name))

        lib_source = open(str(file_path)).read()

        result = []  # type: List[str]
        relative_path = str(file_path.relative_to(lib_path))
        result.append('')
        result.append(f'#pragma region "{relative_path}"')
        result.append('')
        for line in lib_source.splitlines():
            if self.is_ignored_line(line):
                continue

            m = self.inner_include.match(line)
            if m:
                name = m.group(1)
                include_path.append(file_path.parent)
                path = self.find_inner_file(name, include_path)
                if path is not None:
                    result.extend(self.expand_lib(path, include_path))
                else:
                    result.append(line)
                include_path.pop()
                continue

            result.append(line)
        result.append('')
        result.append(f'#pragma endregion "{relative_path}"')
        result.append('')
        return result

    def expand(self, source: str) -> str:
        self.included = set()
        result = []  # type: List[str]
        for line in source.splitlines():
            m = self.library_include.match(line)
            if m:
                file_path = self.find_library_path(m.group(1))
                lib_name = m.group(2)
                include_path = [self.find_library_path(lib_name)]
                result.extend(self.expand_lib(file_path, include_path))
                continue

            result.append(line)
        
        ret = []
        last_empty = True
        for line in result:
            if not line:
                if last_empty: continue
                last_empty = True
            else:
                last_empty = False
            ret.append(line)
        return '\n'.join(ret)


if __name__ == "__main__":
    basicConfig(
        format="%(asctime)s [%(levelname)s] %(message)s",
        datefmt="%H:%M:%S",
        level=getenv('LOG_LEVEL', 'INFO'),
    )
    parser = argparse.ArgumentParser(description='Expander')
    parser.add_argument('source', help='Source File')
    parser.add_argument('lib', help='Path to library directory')
    parser.add_argument('-c', '--console',
                        action='store_true', help='Print to Console')
    opts = parser.parse_args()

    lib_path = Path(opts.lib)
    expander = Expander(lib_path)
    source = open(opts.source).read()
    output = expander.expand(source)

    if opts.console:
        print(output)
    else:
        with open('combined.cpp', 'w') as f:
            f.write(output)
