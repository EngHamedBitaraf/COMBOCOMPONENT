$(document).ready(function() {
  $(".dropdown").hide();
  $(".dropdownchild").hide();
  $(".btn").on("click", function() {
    $(".dropdown").slideToggle("fast");
  });
  
  $(".childtext").on("click", function() {
    $(this).next().slideToggle("fast");
  });
  
  $(".litext").on("click", function() {
    var value = $(this).text();
    $(".txt_basic").val(value);
  });
  
});