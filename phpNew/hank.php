<!DOCTYPE html>
<html>
  <head>
    <title>Hank's Domotics App</title>
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
  	grid-template-columns: 25% 25% 25% 25%;
  	grid-template-rows: 25% 12.5% 25% 12.5% 25%;
	}

	.pic{max-height: 100%; max-width: 100%; margin: auto;}

	.l1{grid-row: 1; grid-column: 1; }
	.bedLight{grid-row: 2; grid-column: 1;}

	.l2{grid-row: 1; grid-column: 2; }
        .tableLight{grid-row: 2; grid-column: 2;}

	.l3{grid-row: 1; grid-column: 3;}
	.windowLight{grid-row: 2; grid-column: 3;}

	.w1{grid-row: 1; grid-column: 4;}
	.window{grid-row: 2; grid-column: 4;}

	.c1{grid-row: 3; grid-column: 1;}
	.caretaker{grid-row: 4; grid-column: 1;}

	.a1{grid-row: 3; grid-column: 2;}
	.emergency{grid-row: 4; grid-column: 2;}

	.msg{grid-area: 3 / 3 / span 2 / span 2;}

	.brightness-Container{
	grid-area: 5 / 1 / span 1 / span 4;
	display: grid;
	grid-template-columns: 1fr 1fr 1fr 1fr 1fr 1fr;
	grid-template-rows: 50% 50%;
	font-size: 3vw;
	}
	.decTableLight{grid-row: 2; grid-column: 1;}
	.valTableLight{grid-row: 2; grid-column: 2; margin: auto;}
	.incTableLight{grid-row: 2; grid-column: 3;}

	.decWindowLight{grid-row: 2; grid-column: 4;}
	.valWindowLight{grid-row: 2; grid-column: 5; margin: auto;}
	.incWindowLight{grid-row: 2; grid-column: 6;}

	.description1{
	font-size: 3vw;
	margin: auto;
	grid-area: 1 / 1 / span 1 / span 3;
	}

	.description2{
	font-size: 3vw;
	margin: auto;
	grid-area: 1 / 4 / span 1 / span 3;
	}

	textarea {
	resize: none;
	font-size: 1.75vw;
	}

	input[type=submit]{
	font-size: 2vw;
	}

	input[value="+"],input[value="-"]{
	font-size: 3vw;
	}

    </style>
  </head>
  <body>
    <p>

<?php
/* requested functionality for frontend
 for hank:
- fridgedoor open for x time
- request caretaker
- control lights
- control window
-notify  when its bedtime
- control table light brightness (and on/off) 


*/
require('functionsHank.php');
header('Refresh: 10;');
read(); // The json needs to be read at startup
checkButton();
write();

?>
<form action="" method="post">
<div class="grid-container">
<img src="<?php echo setImg(bed);?>" class="pic l1">
<img src="<?php echo setImg(table);?>" class="pic l2"> 
<img src="<?php echo setImg(windowLight);?>" class="pic l3"> 
<img src="<?php echo setImg(window);?>" class="pic w1">

<input type="submit" class="bedLight" name="bedLightBtn" value="Bed light on/off" />
<input type="submit" class="tableLight" name="tableLightBtn" value="Table light on/off"/>
<input type="submit" class="windowLight" name="windowLightBtn" value="Window light on/off"/>
<input type="submit" class="window" name="windowBtn" value="Blinds on/off"/>
<img src="Staff.png" class="pic c1">
<img src="Emergency.png" class="pic a1">
<input type="submit" class="caretaker" name="caretakerBtn" value="Request a caretaker" />
<input type="submit" class="emergency" name="emergencyBtn" value="Report an emergency" />
<textarea class="msg" rows=5 cols=50 name="notify" readonly/><?php notify(); echo $message;?></textarea>
	<div class = "brightness-Container">
		<div class="description1">Table light brightness </div>
		<div class="description2">Window light brightness</div>
		<input type="submit" class="decTableLight" name="tableLight-" value="-"/>
		<div class="valTableLight"><?php echo $myobj->brTableLight . "%"; ?></div>
		<input type="submit" class="incTableLight" name="tableLight+" value="+"/>

		<input type="submit" class="decWindowLight" name="windowLight-" value="-"/>
		<div class="valWindowLight"><?php echo $myobj->brWindowLight . "%"; ?></div>
		<input type="submit" class="incWindowLight" name="windowLight+" value="+"/>
	</div>
</div>
</form>
   </p>
  </body>
</html>


