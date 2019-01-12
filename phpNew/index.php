<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>Login page</title>
<style>
body,html {
background-color: #D8DBE2;
}



h2{
text-align: center;
}


input[type=text], input[type=password] {
  width: 100%;
  padding: 12px 20px;
  margin: 8px 0;
  display: inline-block;
  border: 1px solid #ccc;
  box-sizing: border-box;
}

button {
  background-color: #4CAF50;
  color: white;
  padding: 14px 20px;
  margin: 8px 0;
  border: none;
  width: 100%;
}

.container {
  padding: 16px;
}

</style>
</head>
<body>
<?php
if($_POST['uname'] == "hank" && $_POST['psw'] == 123 ){
	header("Location: hank.php");
}
if($_POST['uname'] == "porter" && $_POST['psw'] == 123 ){
	header("Location: porter.php");
}
if($_POST['uname'] == "medic" && $_POST['psw'] == 123 ){
	header("Location: medic.php");
}


?>

<h2>Login</h2>

<form action="" method="post">
  <div class="container">
    <label for="uname"><b>Username:</b></label>
    <input type="text" placeholder="Enter Username" name="uname" required>
    <label for="psw"><b>Password:</b></label>
    <input type="password" placeholder="Enter Password" name="psw" required>
    <button type="submit">Login</button>
  </div>
  </div>
</form>

</body>
</html>

