$('a').on('click', function () {
    $('.button').addClass('connect to db').delay(2400).queue(function () {
        $(this).addClass('connected to db')
    });
});
