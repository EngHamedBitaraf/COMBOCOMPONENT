console.clear();

var backend;
window.onload = function()
    {
        new QWebChannel(qt.webChannelTransport, function(channel) {
            backend = channel.objects.backend;
        });
    }



$("button").on("touchstart mousedown", function () {
	$(this).addClass("clicked");

});

$("button").on("touchend mouseup", function () {
	$(this).removeClass("clicked");
	$(this).blur();

});

$("button").on("click touch", function () {
    
        var visible


	$(this).find(".icn").toggleClass("minus");
	$(this)
		.find(".txt")
		.text(
			$(this).find(".icn").hasClass("minus") == true
                ? "Hide Widget"
                : "Show Widget"


		);
    $(this)
        $(this).find(".icn").hasClass("minus") == true
            ? visible = true
            : visible = false ,backend.visibilityx(visible, function(callback) { result = callback;})


          ;
});
