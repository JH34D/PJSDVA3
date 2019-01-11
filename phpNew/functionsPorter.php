<?php
$myobj;
$path = "/home/pi/workingDir/output.json"; // The location of the JSON file for c++
$message[0]  = "Notifications: ";


// A basic read function. Opens the specified JSON file and puts the data in the object myobj.
      function read() {
        global $myobj, $path;
        $myfile = fopen($path, "r") or die("Unable to open the data file");
        $mystring = fread($myfile, filesize($path));
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

	function setImg($loc){
	global $myobj;
		if($loc == "door"){
			if($myobj->door){
				return "DoorOpen.png";
			}
			else{
				return "DoorClosed.png";
			}
		}
	}

	function openDoor(){
	global $myobj;
		if($myobj->door){
			$myobj->door = 0;
		}
		else{
			$myobj->door = 1;
		}
	}

	function notifications(){
	global $message, $myobj;
	echo "index now is: " . $myobj->msgIndex;
	$message[$myobj->msgIndex++] = "WOW!";
	}

	function checkButton(){

		if(isset($_POST['doorBtn'])){ //check which form was submitted
			openDoor();
			notifications();
		}
	}


?>
