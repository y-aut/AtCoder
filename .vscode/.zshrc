source ~/.zshrc

echo "ttys: $(ls /dev | grep ttys | wc -l | awk '{print $1}') / $(sysctl -a | grep kern.tty.ptmx_max | awk '{print $NF}')"
