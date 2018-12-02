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
    <form action="filled.php" method="post">
      Please enter the prefered ledvalue:<br>
      <input type="text" name="txt"><br>
       <input type="submit" name="setLed" value="Set Leds"> <br>
	 <input type="radio" name="gaga" value="switch" checked> read switchstate<br>
      <input type="radio" name="gaga" value="else">read something else<br>
	<input type="submit" name="read" value="Read"> <br>
    <!-- Select one of these:<br>
     
      Please choose one or more of the following options:<br>
      <input type="checkbox" name="box" value="lights">Turn the lights on/off<br>
      <input type="checkbox" name="box" value="blinds">open/close the blinds<br>
-->
Or reset the page <br>
<input type="reset" value="Reset">
    </form>
  </body>
</html>


