<!DOCTYPE html>
<html>
  <head>
    <title>Dashboard Porter</title>
  <style type="text/css"> 
    body,html {
      background-color: #D8DBE2;
      text-align: center;
    }
	*{
	box-sizing: border-box;
	padding: 0;
	margin: 0;
	}
	.grid-container {
	width: 100vw;
	height: 100vh;
  	display: grid;
  	grid-template-columns: 25% 75%;
  	grid-template-rows: 25% 12.5% 25% 12.5% 25%;
	}

	.pic{max-height: 100%; max-width: 100%; margin: auto;}

	.d1{grid-row:1; grid-column: 1;}
	.door{grid-row:2; grid-column: 1;}

	.msg-container{
	grid-area: 1 / 2 / span 5 / 2;
  	display: grid;
  	grid-template-columns: 75% 25%;
  	grid-template-rows: 10% 22.5% 22.5% 22.5% 22.5%;
	}

	.msgTop{grid-row:1; grid-column: 1;}
	.msg1{grid-row:2; grid-column: 1;}
	.msg2{grid-row:3; grid-column: 1;}
	.msg3{grid-row:4; grid-column: 1;}
	.msg4{grid-row:5; grid-column: 1;}


	.ok1{grid-row:2; grid-column: 2;}
	.ok2{grid-row:3; grid-column: 2;}
	.ok3{grid-row:4; grid-column: 2;}
	.ok4{grid-row:5; grid-column: 2;}


	textarea {
	resize: none;
	font-size: 1.75vw;
	}

	input[type=submit]{
	font-size: 2vw;
	}

	input[value="X"]{
	background-color: Transparent;
	border: none;
	}

    </style>
  </head>
  <body>
    <p>

<?php
/* requested functionality for frontend
 for the porter:
- Open the door
- see alarms/ see alarm after time
- notify  when not in bed
- ... 


*/
require('functionsPorter.php');
header('Refresh: 10;');
read(); // The json needs to be read at startup
checkButton();
write();

?>
<form action="" method="post">
<div class="grid-container">
<img src="<?php echo setImg(door);?>" class="pic d1">
<input type="submit" class="door" name="doorBtn" value="Open/Close door"/>
<div class="msg-container">
<div class="msgTop"><?php echo $message[0] . " <br>"; ?> </div>
<div class="msg1"><?php echo $message[1] . " <br>"; ?> </div>
<input type="submit" class="ok1" name="close1Btn" value="X"/>
<div class="msg2"><?php echo $message[2] . " <br>"; ?> </div>
<input type="submit" class="ok2" name="close2Btn" value="X"/>
<div class="msg3"><?php echo $message[3] . " <br>"; ?> </div>
<input type="submit" class="ok3" name="close3Btn" value="X"/>
<div class="msg4"><?php echo $message[4] . " <br>"; ?> </div>
<input type="submit" class="ok4" name="close4Btn" value="X"/>
</div>
</div>
</form>
   </p>
  </body>
</html>


