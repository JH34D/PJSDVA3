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

<?php
$path = "/home/pi/workingDir/output.txt";
 if (isset($_POST["setLed"])){ ?>
Hi there. Your input was:
<?php echo $_POST["txt"]; ?><br> 
<?php
$myfile = fopen($path, "w") or die("Unable to open file!");
fwrite($myfile, "led " . $_POST["txt"]);
fclose($myfile);
} 
else { //read. met meer knoppen naar else if
?>
The button you chose was:
<?php echo $_POST["gaga"]; ?><br>
<?php
$myfile = fopen($path, "w") or die("Unable to open file!");
fwrite($myfile, "switches");
fclose($myfile);
$timeModified = filectime($path);
do{
clearstatcache();
$newTime = filectime($path);
	if($newTime > $timeModified){
		break;
	}
}while(true); //while the file is unchanged

$myfile = fopen($path, "r") or die("Unable to open file!");
$output = fread($myfile, 25); //filesize($path)); DOENST WORK?!?!
echo "The current switchvalue is: " . $output;
fclose($myfile);
}
?> <br>

 
<a href="index.php">click here</a> to go back to the form page.
  </body>
</html>

