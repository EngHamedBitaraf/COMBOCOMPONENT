var $cta = $('.cta');

function drawGlow(e) {
	var $t = $(this)
	var x = e.pageX - $t.offset().left; 
	var y = e.pageY - $t.offset().top; 
	$t.find('.hover-glow').css({
		'transform': 'translate('+x +'px,' + y  +'px)',
		'opacity': 1
	})
}

function killGlow() {
	var $t = $(this);
	$t.find('.hover-glow').css({
		'opacity' : 0
	})
}


$cta.on({
	'mousemove': drawGlow,
	'mouseleave': killGlow
})