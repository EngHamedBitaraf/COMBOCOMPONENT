console.clear();

$("button").on("touchstart mousedown", function () {
	$(this).addClass("clicked");
});

$("button").on("touchend mouseup", function () {
	$(this).removeClass("clicked");
	$(this).blur();
});

$("button").on("click touch", function () {
	$(this).find(".icn").toggleClass("minus");
	$(this)
		.find(".txt")
		.text(
			$(this).find(".icn").hasClass("minus") == true
				? "Less details"
				: "More details"
		);
});
