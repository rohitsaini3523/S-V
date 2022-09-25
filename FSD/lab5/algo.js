function set_error(id, error) {
  element = document.getElementById(id);
  element.getElementsByClassName("form_error")[0].innerHTML = error;
}

function clearErrors() {
  errors = document.getElementsByClassName("form_error");
  for (let item of errors) {
    item.innerHTML = "";
  }
}

function validate_form() {
  var return_value = true;
  clearErrors();

  var name = document.forms["myform"]["fname"].value;
  if (name.length < 5) {
    set_error("name", "*Length of name is too short");
    return_value = false;
  }
  if (name.length > 20) {
    set_error("name", "*Length of name is too Long");
    return_value = false;
  }
  
  var email = document.forms["myform"]["femail"].value;
  if (email.length > 30) {
    set_error("email", "*Length of Email is too long");
    return_value = false;
  }

  var phno = document.forms["myform"]["fphno"].value;
  if (phno.length != 10) {
    set_error("phno", "*Phone number of should be 10 Digits");
    return_value = false;
  }

  var pass = document.forms["myform"]["fpass"].value;
  if (pass.length < 8 || pass.length > 20) {
    set_error("pass", "*Enter password between 8 to 20 characters");
    return_value = false;
  }
  var cpass = document.forms["myform"]["fcpass"].value;
  if (cpass != pass) {
    set_error("cpass", "*Password and Confirm password should be same");
    return_value = false;
  }
  return return_value;
}

function changeImage() {
  var image = document.getElementById("status_profile");
  if (image.src.match("profile1")) {
    image.src = "profile.jpg";
  } else {
    image.src = "profile1.jpg";
  }
}
