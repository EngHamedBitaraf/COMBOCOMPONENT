$('a').on('click', function () {
    $('.button').addClass('connect').delay(2400).queue(function () {
        $(this).addClass('connected')
    });
});