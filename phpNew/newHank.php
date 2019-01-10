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

	.msg{grid-area: 1 / 3 / span 2 / span 2;}
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
<input type="submit" class="light" name="bedLightBtn" value="Bedlight" />
<input type="submit" class="light" name="tableLightBtn" value="Tablelight"/>
<textarea class="msg" rows=5 cols=50 name="notify" readonly/><?php notify(); echo $message;?></textarea><br>
<input type="submit" class="door" name="doorBtn" value="Request going outdoor" />
<input type="submit" class="window" name="windowBtn" value="Window"/>
</div>
</form>
   </p>
  </body>
</html>


