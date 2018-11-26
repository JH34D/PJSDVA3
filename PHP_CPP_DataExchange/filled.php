<!DOCTYPE html>
<html>
  <head>
    <title>Monitor Drunk Dude</title>
    <style type="text/css">
  body,html {
    padding: 3px 3px 3px 3px;
    background-color: #D8DBE2;
    font-family: Verdana, sans-serif;
    font-size: 11pt;
    text-align: center;
  }
    </style>
  </head>
  <body>
Hi there. Your input was:
<?php echo $_POST["txt"]; ?><br>
The button you chose was:
<?php echo $_POST["gaga"]; ?><br>
<?php
$path = "/mnt/c/forLinux/output.txt";
$myfile = fopen($path, "r") or die("Unable to open file!");
echo "textfile data is: " . fread($myfile,filesize($path));
fclose($myfile);
?> <br>
<?php
$myfile = fopen($path, "w") or die("Unable to open file!");
fwrite($myfile, "r led " . $_POST["txt"]);
fclose($myfile);
?>
<a href="index.php">click here</a> to go back to the form page.
  </body>
</html>
