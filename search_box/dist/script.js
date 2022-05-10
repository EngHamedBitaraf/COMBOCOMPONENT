var backend;
window.onload = function()
    {
        new QWebChannel(qt.webChannelTransport, function(channel) {
            backend = channel.objects.backend;
        });
    }
        $(document).ready(function(){
    $("#search").focus(function() {
      $(".search-box").addClass("border-searching");
      $(".search-icon").addClass("si-rotate");
    });
    $("#search").blur(function() {
      $(".search-box").removeClass("border-searching");
      $(".search-icon").removeClass("si-rotate");
    });
    $("#search").keyup(function() {
        if($(this).val().length > 0) {
          $(".go-icon").addClass("go-in");
        }
        else {
          $(".go-icon").removeClass("go-in");
        }
    });
    $(".go-icon").click(function(){
          getInputValue();
        });
        function getInputValue(){
                // Selecting the input element and get its value
                var inputVal = document.getElementById("search").value;

                // Displaying the value
            backend.searchbox(inputVal, function(callback) {
                result = callback;
            });
            }
    });
