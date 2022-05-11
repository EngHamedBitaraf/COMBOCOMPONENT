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
    
        var abbas = ""


	$(this).find(".icn").toggleClass("minus");
	$(this)
		.find(".txt")
		.text(
			$(this).find(".icn").hasClass("minus") == true
                ? "Less details"
                : "More details"


		);
    $(this)
        $(this).find(".icn").hasClass("minus") == true
            ? abbas = "extra_detail"
            : abbas = "less_detail" ,backend.changeText(abbas, function(callback) { result = callback;})


          ;
});
