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
  	grid-template-rows: 25% 25% 25% 25%;
	}

	.pic{max-height: 100%; max-width: 100%; margin: auto;}

	.l1{grid-row: 1; grid-column: 1; }
	.bedLight{grid-row: 2; grid-column: 1;}
	.l2{grid-row: 1; grid-column: 2; }
        .tableLight{grid-row: 2; grid-column: 2;}
	.msg{grid-area: 1 / 3 / span 2 / span 2;}
	.door{grid-row: 3; grid-column: 1;}
	.window{grid-row: 3; grid-column: 2;}

	textarea {
	resize: none;
	}

    </style>
  </head>
  <body>
    <p>

<?php
/* requested functionality for frontend
 for hank:
- fridgedoor open for x time
- request going outside
- control lights
- control window
-notify  when its bedtime
- control table light brightness (and on/off) 


*/
require('functions.php');
header('Refresh: 10;');
read(); // The json needs to be read at startup
checkButton();
write();

?>
<form action="" method="post">
<div class="grid-container"> 
<input type="submit" class="bedLight" name="bedLightBtn" value="Bedlight" />
<input type="submit" class="tableLight" name="tableLightBtn" value="Tablelight"/>
<textarea class="msg" rows=5 cols=50 name="notify" readonly/><?php notify(); echo $message;?></textarea><br>
<input type="submit" class="door" name="doorBtn" value="Request going outdoor" />
<input type="submit" class="window" name="windowBtn" value="Window"/>
<img src="<?php echo setImg(bed);?>" class="pic l1">
<img src="<?php echo setImg(table);?>" class="pic l2">
</div>
</form>
   </p>
  </body>
</html>


