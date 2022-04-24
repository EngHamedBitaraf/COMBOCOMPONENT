$(document).ready(function(){
  $('.multi-button').on('click', 'button', function() {
  $(this).addClass('active').siblings().removeClass('active');
});
});