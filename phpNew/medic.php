<!DOCTYPE html>
<html>
  <head>
    <title>Dashboard Medic</title>
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
  	grid-template-rows: 10% 1fr 1fr 1fr 1fr 1fr;
	font-size: 2vw;
	}

	.cntr{margin: auto;}
	.msgTop{grid-row:1; grid-column: 1;}
	.msg1{grid-row:2; grid-column: 1;}
	.msg2{grid-row:3; grid-column: 1;}
	.msg3{grid-row:4; grid-column: 1;}
	.msg4{grid-row:5; grid-column: 1;}
	.msg5{grid-row:6; grid-column: 1;}


	.ok1{grid-row:2; grid-column: 2;}
	.ok2{grid-row:3; grid-column: 2;}
	.ok3{grid-row:4; grid-column: 2;}
	.ok4{grid-row:5; grid-column: 2;}
	.ok5{grid-row:6; grid-column: 2;}

	input[type=submit]{
	font-size: 2vw;
	}

	input[class*="ok"]{
	background-color: Transparent;
	border: none;
	}

    </style>
  </head>
  <body>
    <p>

<?php
require('functionsMedic.php');
header('Refresh: 5;');
read(); // The json needs to be read at startup
checkButton();
write();
?>
<form action="" method="post">
<div class="grid-container">
	<img src="<?php echo setImg(door);?>" class="pic d1">
	<input type="submit" class="door" name="doorBtn" value="Open/Close door"/>
	<div class="msg-container">
		<div class="msgTop cntr"><?php echo $message[0][0] . " <br>"; ?> </div>
		<div class="msg1 cntr"><?php echo $message[1][0] . " <br>"; ?> </div>
		<?php if(setClose(1)){?><input type="submit" class="ok1" name="close1Btn" value="X"/><?php } ?>
		<div class="msg2 cntr"><?php echo $message[2][0] . " <br>"; ?> </div>
		<?php if(setClose(2)){?><input type="submit" class="ok2" name="close2Btn" value="X"/><?php } ?>
		<div class="msg3 cntr"><?php echo $message[3][0] . " <br>"; ?> </div>
		<?php if(setClose(3)){?><input type="submit" class="ok3" name="close3Btn" value="X"/><?php } ?>
		<div class="msg4 cntr"><?php echo $message[4][0] . " <br>"; ?> </div>
		<?php if(setClose(4)){?><input type="submit" class="ok4" name="close4Btn" value="X"/><?php } ?>
		<div class="msg5 cntr"><?php echo $message[5][0] . " <br>"; ?> </div>
		<?php if(setClose(5)){?><input type="submit" class="ok5" name="close5Btn" value="X"/><?php } ?>
	</div>
</div>
</form>
</p>
</body>
</html>


