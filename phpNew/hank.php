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

    /* This part of the CSS is created to make sure the images are easily aligned in boxes.
       only column 1 and 2 are used in the current build, but for easy remodeling 3 till 8 are still present.
       Images will span accross the entire column with 10 pixels of padding 
    */
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
$path = "/home/pi/workingDir/output.json"; // The location of the JSON file
      read(); // The json needs to be read at startup

      // A basic read function. Opens the specified JSON file and puts the data in the object myobj.
      function read() {
        global $myobj, $path;
        $myfile = fopen($path, "r") or die("Unable to open the data file");
        $mystring = fread ($myfile, filesize($path));
        fclose($myfile);
        $myobj = json_decode($mystring);
      }

      // A basic write function. Encodes myobj to json and then writes it to the specified file.
      function write() {
        global $myobj, $path;
        $myJSON = json_encode($myobj);
        $myfile = fopen($path, "w") or die("Unable to open the data file");
        fwrite($myfile, $myJSON);
        fclose($myfile);
      }

      // The following functions (bed, door, lamp and blinds) all serve the same function of being a simple switch.
      // They will check the current status and switch to the other status.
      function bed() {
        global $myobj;
        if ($myobj->bedlight == 1) {
          $myobj->bedlight = 0;
        } else {
          $myobj->bedlight = 1;
        }
        write();
        echo " ";
      }
	  
	  function door() {
        global $myobj;
        if ($myobj->doorlight == 1) {
          $myobj->doorlight = 0;
        } else {
          $myobj->doorlight = 1;
        }
        write();
        echo " ";
      }
	  
	  function lamp() {
        global $myobj;
        if ($myobj->lamp == 1) {
          $myobj->lamp = 0;
        } else {
          $myobj->lamp = 1;
        }
        write();
        echo " ";
      }
	  
	  function blinds() {
        global $myobj;
        if ($myobj->blinds == 1) {
          $myobj->blinds = 0;
        } else {
          $myobj->blinds = 1;
        }
        write();
        echo " ";
      }

      // Staff and emergency are simpler buttons. They can only be triggered, and can only be reset by staff.
      function staff() {
        global $myobj;
        $myobj->staff = 1;
        write();
        echo " ";
      }
	  
      function emergency() {
        global $myobj;
        $myobj->emergency = 1;
        write();
        echo " ";
      }

      // A simple function that writes the pushed button for the led strip to JSON.
	  function led($x) {
        global $myobj;
        $myobj->led = $x;
        write();
        echo " ";
	  }
    ?>
    //The first row just consists of titles, telling Hank which button corresponds to which light.
    <div class="row">
      <div class="col-2"><h3>Bed Light</h3></div>
      <div class="col-2"><h3>Door Light</h3></div>
      <div class="col-2"><h3>Lamp Light</h3></div>
      <div class="col-2"><h3>LED-strip lights</h3></div>
    </div>
    /* The site is divided into two rows, both carrying five columns.
       Three of these columns span about 25% of the width of the screen, whereas the last two only span 12,5%.
       The smaller buttons are for the led strip. Their order might seem odd, due to the columns needing to be the same height.
    */
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

      /* On Hank's page, javascript doesn't play a big role. It is only used to make sure the php functions are called.
         After executing a function, the page has to reload to make sure the write() is registered and to make sure reading works properly.
         All functions except LED serve the simple purpose of being just a simple call.
      */
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

      // Switches based on the given input, making sure the correct number is writen. Currently broken, always picks the last case.
      function switchLED(num) {
        switch(num) {
		  case 0:
		    var result = "<?php led(0);?>";
			break;
	      case 1:
		    var result = "<?php led(1);?>";
			break;
	      case 2:
		    var result = "<?php led(2);?>";
			break;
		  case 3:
		    var result = "<?php led(3);?>";
			break;
	      case 4:
		    var result = "<?php led(4);?>";
			break;
	      case 5:
		    var result = "<?php led(5);?>";
			break;
		  case 6:
		    var result = "<?php led(6);?>";
			break;
                  case 7:
                    var result = "<?php led(7);?>";
                      break;
		  default:
                alert("Triggered, but no value.");
		}
             location.reload();
      }

    </script>
  </body>
</html>


