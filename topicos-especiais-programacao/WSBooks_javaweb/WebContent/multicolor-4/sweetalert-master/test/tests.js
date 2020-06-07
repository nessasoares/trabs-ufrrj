// swal() sould add the modal to the DOM + make it visible
test("modal shows up", function() {
  equal($('.sweet-alert').length, 0);

  swal("Hello world!");
  
  ok($('.sweet-alert').is(':visible'));
});

