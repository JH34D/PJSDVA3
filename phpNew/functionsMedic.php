<?php
$myobj;
$path = "/home/pi/workingDir/output.json"; // The location of the JSON file for c++
$message[0][0]  = "Notifications: ";


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
	if($myobj->notInBed){ //count-1 or var=count then use var..
		$message[count($message)][0] = "Hank is currently not in bed.";
		$message[count($message)-1][1] = "notInBed";
	}
	if($myobj->emergency){
		$message[count($message)][0] = "Hank reported an emergency!";
		$message[count($message)-1][1] = "emergency";
	}
	if($myobj->aggressive){
		$message[count($message)][0] = "Hank is currently aggressive.";
		$message[count($message)-1][1] = "aggressive";
	}
	if($myobj->fire){
		$message[count($message)][0] = "Smoke has been detected in Hank's room!";
		$message[count($message)-1][1] = "fire";
	}
	if($myobj->help){
		$message[count($message)][0] = "Hank has requested help.";
		$message[count($message)-1][1] = "help";
	}

	}

	function resetMsg($pos)
	{
		global $myobj, $message;
		if(isset($message[$pos][0])){
			$message[$pos][0] = NULL;
			$myobj->{$message[$pos][1]} = 0;
		}
	}


	function setClose($pos){
	global $message;
	if(isset($message[$pos][0])){
		return 1;
	}
	else{
		return 0;
	}
	}

	function checkButton(){
	notifications();
		if(isset($_POST['doorBtn'])){
			openDoor();
		}
		if(isset($_POST['close1Btn'])){
			resetMsg(1);
		}
		if(isset($_POST['close2Btn'])){
			resetMsg(2);
		}
		if(isset($_POST['close3Btn'])){
			resetMsg(3);
		}
		if(isset($_POST['close4Btn'])){
			resetMsg(4);
		}
		if(isset($_POST['close5Btn'])){
			resetMsg(5);
		}
	}


?>
