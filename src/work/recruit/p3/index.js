$(function () {
    // 値段を表示するラベルを作成
    $('.menuItem button').each(function () {
        const price = $(this).data('price');
        $(this).append(`<span class="priceLabel">${price} 円</span>`);
    });

    // ボタンクリック時の処理を登録
    $('.menuItem button').click(function () {
        // 商品ごとの購入個数を増やす
        const count = $(this).siblings('.itemCount')
        count.text(Number(count.text()) + 1);
        // 合計を増やす
        $('#count').text(Number($('#count').text()) + 1);
        $('#price').text(Number($('#price').text()) + Number($(this).data('price')));
    });
});
