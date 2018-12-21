<!DOCTYPE html>
<html>
  <head>
    <title>Medic: Monitoring Hank</title>
    <style type="text/css">
      body,html {
        background-color: #D8DBE2;

        font-family: Arial, sans-serif;
        text-align: center;
      }
      div {
        box-sizing: border-box;
      }
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
      $path = "/var/www/html/jason.json";
      read();

      function read() {
        global $path, $myobj;
        $myfile = fopen($path, "r") or die("Unable to open the data file");
        $mystring = fread ($myfile, filesize($path));
        fclose($myfile);
        $myobj = json_decode($mystring);
      }

      function write() {
        global $myobj, $path;
        $myJSON = json_encode($myobj);
        $myfile = fopen($path, "w") or die("Unable to open the data file");
        fwrite($myfile, $myJSON);
        fclose($myfile);
      }

      function dooropen() {
        global $myobj;
        if ($myobj->dooropen == 1) {
          $myobj->dooropen = 0;
          echo "The door has been closed.";
        } else {
          $myobj->dooropen = 1;
          echo "The door has been opened.";
        }
        write();
      }

      function checkCalls() {
        global $myobj;
        if ($myobj->emergency == 1) {
          echo "There is an emergency! Press the emergency button once the problem is resolved.";
        } else if ($myobj->staff == 1) {
          echo "Hank has called for staff. Please press the staff button once the problem is resolved.";
        } else if ($myobj->aggressive == 1) {
          echo "Hank is aggressive. Please press the aggression button once the problem is resolved.";
        } else {
          echo "0";
        }
      }

      function resetEmergency() {
        global $myobj;
        $myobj->emergency = 0;
        write();
      }

      function resetStaff() {
        global $myobj;
        $myobj->staff = 0;
        write();
      }

      function resetAggressive() {
        global $myobj;
        $myobj->aggressive = 0;
        write();
      }

    ?>
    <h1>Monitoring: Hank.</h1></br>
    <img src="LightOn.png" alt="Lights are on.">
    <img src="bed.png" alt="Hank is in bed.">
    <img src="Door.png" alt="Door button" onClick="doorswitch()">
    <img src="Fist.png" alt="Hank is currently not aggressive." onClick="stopAggressive()">
    <img src="Staff.png" alt="Hank doens't need assistance." onClick="stopStaff()">
    <img src="Emergency.png" alt="There is no alert." onClick="stopEmergency()">
	<script language="javascript">
	  function doorswitch() {
		var result = "<?php dooropen();?>";
                alert(result);
		location.reload();
	  }

          window.onload = function(){
            var result="<?php checkCalls();?>";
            if (result!="0") {
              alert(result);
            }
          };

          function stopEmergency() {
            var result = "<?php resetEmergency();?>";
            location.reload();
          }

          function stopStaff() {
            var result = "<?php resetStaff();?>";
            location.reload();
          }

          function stopAggressive() {
            var result = "<?php resetAggressive();?>"
            location.reload();
          }

          setInterval(function(){
            var result="<?php checkCalls();?>";
            if (result=="0") {
              location.reload();
            }
          }, 5000);
	</script>
  </body>
</html>


