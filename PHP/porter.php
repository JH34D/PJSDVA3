<!DOCTYPE html>
<html>
  <head>
    <title>Porter: Monitoring Hank</title>
    <style type="text/css">
      body,html {
        background-color: #D8DBE2;

        font-family: Arial, sans-serif;
      }
      div {
        box-sizing: border-box;
      }
      // The following code makes sure the images align correctly in both landscape and portrait mode.
      @media only screen and (max-width: 800px) {
        img {
          width: 40%;
          align: left;
          padding-left: 4%;
          padding-right: 4%;
          padding-bottom: 2%;
        }
        h1 {font-size: 24pt;}
      }
      @media only screen and (min-width: 800px) {
        img {
          width: 25%;
          align: left;
          padding-left: 3%;
          padding-right: 3%;
          padding-bottom: 1%;
        }
        h1 {font-size: 36-pt;]
      }
    </style>
  </head>
  <body>
  <?php
      $path = "/var/www/html/jason.json"; // The location of the JSON file
      read();

      // A simple read function. Reads from the specified file, decodes the JSON and stores the results as an object.
      function read() {
        global $path, $myobj;
        $readfile = fopen($path, "r") or die("Unable to open the data file");
        $mystring = fread ($readfile, filesize($path));
        fclose($readfile);
        $myobj = json_decode($mystring);
      }

      // A simple write function. Encodes our object to JSON and stores the result in the specified file.
      function write() {
        global $myobj, $path;
        $myJSON = json_encode($myobj);
        $myfile = fopen($path, "w") or die("Unable to open the data file");
        fwrite($myfile, $myJSON);
        fclose($myfile);
      }
	  
      // A simple statement functioning as a switch to open the door.
	  function dooropen() {
        global $myobj;
        read();
        if ($myobj->dooropen == "1") {
          $myobj->dooropen = "0";
          echo "The door has been closed.";
        } else {
          $myobj->dooropen = "1";
          echo "The door has been opened.";
        }
        write();
      }

      // Checks if any important calls have been made and returns them to Javascript.
      function checkCalls() {
        global $myobj;
        if ($myobj->emergency == 1) {
          echo "There is an emergency! Press the emergency button once the problem is resolved.";
        } else if ($myobj->staff == 1) {
          echo "Hank has called for staff. Please press the staff button once the problem is resolved.";
        } else {
          echo "0";
        }
      }

      // Both of the following functions reset the calls.
      function resetEmergency() {
        global $myobj;
        $myobj->staff = 0;
        write();
      }

      function resetStaff() {
        global $myobj;
        $myobj->staff = 0;
        write();
      }
    ?>
    // The code that makes sure the images are properly aligned is fixed in the CSS here, so the html code itself is short and simple.
    <img src="Hank.png" alt="Monitoring: Hank.">
    <img src="LightOn.png" alt="Lights are on.">
    <img src="bed.png" alt="Hank is in bed.">
    <img src="Door.png" alt="Door button" onClick="opendoor()">
    <img src="Staff.png" alt="Hank doens't need assistance." onClick="stopStaff()">
    <img src="Emergency.png" alt="There is no alert." onClick="stopEmergency()">

    <script language="javascript">
          // A simple php function call to open the door.
	  function opendoor() {
		var result="<?php dooropen();?>";
		alert(result);
                location.reload();
          }

          // Checks for calls upon loading, immediately sending an alert if any have been triggered.
          window.onload = function(){
            var result="<?php checkCalls();?>";
            if (result!="0") {
              alert (result);

          // The following to functions are simple php function calls to reset the calls
          function stopEmergency() {
            var result="<?php resetEmergency();?>";
            location.reload();
          }

          function stopStaff() {
            var result="<?php resetStaff();?>";
            location.reload();
          }

          // As long as no alerts have been triggered, reloads the page every 5000 ms to check for calls again.
	  setInterval(function(){
            var result="<?php php checkCalls();?>";
            if (result=="0") {
              location.reload();
            }
          }, 5000);
	</script>
  </body>
</html>


