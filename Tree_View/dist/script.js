var backend;
window.onload = function()
    {
        new QWebChannel(qt.webChannelTransport, function(channel) {
            backend = channel.objects.backend;
        });
    }



$(document).ready(function() {
  $(".dropdown").hide();
  $(".dropdownchild").hide();
  $(".btn").on("click", function() {
    $(".dropdown").slideToggle("slow");
  });
  
  $(".childtext").on("click", function() {
    $(this).next().slideToggle("fast");
  });
  
  $(".litext").on("click", function() {
      backend.change_Text_tree_v($(this).text(), function(callback) {
          result = callback;
     });
    var value = $(this).text();
    $(".txt_basic").val(value);
  });
  
});
