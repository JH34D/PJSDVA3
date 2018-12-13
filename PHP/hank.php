<!DOCTYPE html>
<html>
  <head>
    <title>Hank's Domotics App</title>
    <style type="text/css">
    body,html {
      background-color: #D8DBE2;
      height: 100%;
      text-align: center;
    }
    * {
      box-sizing: border-box;
    }
    .col-1 {width: 12.5%}
    .col-2 {width: 25%;}
    .col-3 {width: 37.5%;}
    .col-4 {width: 50%;}
    .col-5 {width: 62.5%;}
    .col-6 {width: 75%;}
    .col-7 {width: 87.5%;}
    .col-8 {width: 100%;}
    [class*="col-"] {
      float: left;
      padding: 10px;
    }
    img {
      object-fit: cover;
      width: 100%;
      max-height: 100%;
    }
    .row::after {
      content: "";
      clear: both;
      display: table;
    }
    </style>
  </head>
  <body>
    <p>
    <?php
      $path = "/var/www/html/jason.json";

      $myfile = fopen($path, "r") or die("Unable to open the data file");
      $mystring = fread ($myfile, filesize($path));
      fclose($myfile);
      $myobj = json_decode($mystring);

      function write() {
        global $myobj, $path;
        $myJSON = json_encode($myobj);
        $myfile = fopen($path, "w") or die("Unable to open the data file");
        fwrite($myfile, $myJSON);
        fclose($myfile);
      }

      function bed() {
        global $myobj;
        if ($myobj->bedlight == "1") {
          $myobj->bedlight = "0";
        } else {
          $myobj->bedlight = "1";
        }
        write();
      }
	  
	  function door() {
        global $myobj;
        if ($myobj->doorlight == "1") {
          $myobj->doorlight = "0";
        } else {
          $myobj->doorlight = "1";
        }
        write();
      }
	  
	  function lamp() {
        global $myobj;
        if ($myobj->lamp == "1") {
          $myobj->lamp = "0";
        } else {
          $myobj->lamp = "1";
        }
        write();
      }
	  
	  function blinds() {
        global $myobj;
        if ($myobj->blinds == "1") {
          $myobj->blinds = "0";
        } else {
          $myobj->blinds = "1";
        }
        write();
      }
	  
	  function staff() {
        global $myobj;
        if ($myobj->staff == "1") {
          $myobj->staff = "0";
        } else {
          $myobj->staff = "1";
        }
        write();
      }
	  
	  function emergency() {
        global $myobj;
        if ($myobj->emergency == "1") {
          $myobj->emergency = "0";
        } else {
          $myobj->emergency = "1";
        }
        write();
      }
	  
	  function led(&$x) {
        global $myobj;
        $myobj->led = $x;	
	  }
    ?>
    <div class="row">
      <div class="col-2"><h3>Bed Light</h3></div>
      <div class="col-2"><h3>Door Light</h3></div>
      <div class="col-2"><h3>Lamp Light</h3></div>
      <div class="col-2"><h3>LED-strip lights</h3></div>
    </div>
    <div class="row">
      <div class="col-2"><img src="LightOn.png" id="bed" alt="Operate Bed Light" onClick="switchBed()"></div>
      <div class="col-2"><img src="LightOn.png" id="door" alt="Operate Door Light" onClick="switchDoor()"></div>
      <div class="col-2"><img src="LightOn.png" id="lamp" alt="Operate Lamp Light" onClick="switchLamp()"></div>
      <div class="col-1">
        <img src="six.png" style="padding-bottom:7%" id="six" alt="LED 6" onClick="switchLED(6)">
        </br>
        <img src="four.png" id="four" alt="LED 4" onClick="switchLED(4)">
      </div>
      <div class="col-1">
        <img src="seven.png" style="padding-bottom:7%" id="seven" alt="LED 7" onClick="switchLED(7)">
        </br>
        <img src="five.png" id="five" alt="LED 5" onClick="switchLED(5)">
      </div>
    </div>
    <div class="row">
      <div class="col-2"><img src="BlindsClosed.png" alt="Operate Blinds Closed" id="blinds" onClick="switchBlinds()"></div>
      <div class="col-2"><img src="Staff.png" alt="Call Staff" id="staff" onClick="staff()"></div>
      <div class="col-2"><img src="Emergency.png" alt="Emergency" id="emergency" onClick="emergency()"></div>
      <div class="col-1">
        <img src="two.png" style="padding-bottom:7%" id="two" alt="LED 2" onClick="switchLED(2)">
        </br>
        <img src="zero.png" id="zero" alt="LED off" onClick="switchLED(0)">
      </div>
      <div class="col-1">
        <img src="three.png" style="padding-bottom:7%" id="three" alt="LED 3" onClick="switchLED(3)">
        </br>
        <img src="one.png" id="one" alt="LED 1" onClick="switchLED(1)">
      </div>
    </div>
    </p>
    <script language="javascript">

      function switchBed() {
        var result = "<?php bed();?>";
        location.reload();
      }

      function switchDoor() {
        var result = "<?php door();?>";
        location.reload();
      }

      function switchLamp() {
        var result = "<?php lamp();?>";
        location.reload();
      }

      function switchBlinds() {
        var result = "<?php blinds();?>";
        location.reload();
      }

      function staff() {
        var result = "<?php staff();?>";
        location.reload();
      }

      function emergency() {
        var result = "<?php emergency();?>";
        location.reload();
      }

      function switchLED(num) {
        switch(num) {
		  case 0:
		    var result = "<?php led(0);?>";
		    location.reload();
			break;
	      case 1:
		    var result = "<?php led(1);?>";
		    location.reload();
			break;
	      case 2:
		    var result = "<?php led(2);?>";
		    location.reload();
			break;
		  case 3:
		    var result = "<?php led(3);?>";
		    location.reload();
			break;
	      case 4:
		    var result = "<?php led(4);?>";
		    location.reload();
			break;
	      case 5:
		    var result = "<?php led(5);?>";
		    location.reload();
			break;
		  case 6:
		    var result = "<?php led(6);?>";
		    location.reload();
			break;
		  case 7:
		    var result = "<?php led(7);?>";
			location.reload();
			break;
		}
      }

    </script>
  </body>
</html>


