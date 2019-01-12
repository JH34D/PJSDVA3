<?php
$myobj;
$path = "/home/pi/workingDir/output.json"; // The location of the JSON file for c++
$message = "Hello Hank, here you will find your reminders:\n\r";

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

        function notify(){
        global $myobj,$message;
		if($myobj->fridge == 1){
			$message .= "- It appears you left the fridgedoor open.\n  Please close it.\n\r";
		}
		if($myobj->bedtime == 1){
			$message .= "- It is currently past 22:00.\n  Please go to bed and try to sleep.\n\r";
		}
        }

        function brightness($loc, $val){
		global $myobj;
		if($loc == "table"){
			$myobj->brTableLight += $val;
			if($myobj->brTableLight > 100){
				$myobj->brTableLight = 100;
			}
			else if ($myobj->brTableLight <= 0){
				$myobj->brTableLight = 0;
				$myobj->tablelight = 0;
			}
			else{
				$myobj->tablelight = 1;
			}
		}
		if($loc == "window"){
			$myobj->brWindowLight += $val;
			if($myobj->brWindowLight > 100){
				$myobj->brWindowLight = 100;
			}
			else if ($myobj->brWindowLight <= 0){
				$myobj->brWindowLight = 0;
				$myobj->windowLight = 0;
			}
			else{
				$myobj->windowLight = 1;
			}
		}
	}

        function requestCaretaker(){
		global $myobj;
		$myobj->help = 1;

        }
        function emergency(){
		global $myobj;
		$myobj->emergency = 1;

        }
	function controlLights($loc){
	global $myobj;
                switch($loc){
		case "bed":
			if($myobj->bedlight == 0){
				$myobj->bedlight = 1;
			}
			else{
				$myobj->bedlight = 0;
                        }
		 break;
		 case "table":
                        if($myobj->tablelight == 0){
                                $myobj->tablelight = 1;
				if($myobj->brTableLight == 0){
					$myobj->brTableLight = 50;
				}
                        }
                        else{
                                $myobj->tablelight = 0;
                        }

                break;
		case "windowLight":
                        if($myobj->windowLight == 0){
                                $myobj->windowLight = 1;
				if($myobj->brWindowLight == 0){
					$myobj->brWindowLight = 50;
				}
                        }
                        else{
                                $myobj->windowLight = 0;
                        }
                 break;

                default:
                        echo "error when setting lights";
                }
        }

        function controlWindow(){
		global $myobj;
		if($myobj->window == 0){
        		$myobj->window = 1;
		}
        	else{
        		$myobj->window = 0;
        	}
        }

	function setImg($loc){
		global $myobj;
		$res;
		switch($loc){
                case "bed":
                	$res = $myobj->bedlight;
                 break;
                 case "table":
                       $res = $myobj->tablelight;
                break;
		case "windowLight":
                        $res = $myobj->windowLight;
                 break;
		case "window":
		global $myobj;
			if($myobj->window){
				return "BlindsClosed.png";
			}
			else{
				return "BlindsOpen.png";
			}
		break;
                default:
                       $res = 0;
                }

		if($res){
			return "LightOn.png";
		}
		else{
			return "LightOff.png";
		}


	}

	function checkButton(){

		if(isset($_POST['bedLightBtn'])){ //check which form was submitted
			controlLights("bed");
		}
		if(isset($_POST['tableLightBtn'])){ 
			controlLights("table");
		}
		if(isset($_POST['caretakerBtn'])){ 
                       requestCaretaker();
                }
		if(isset($_POST['windowBtn'])){ 
                       controlWindow();
                }
		if(isset($_POST['tableLight+'])){ 
                       brightness("table",10);
                }
		if(isset($_POST['tableLight-'])){ 
                       brightness("table",-10);
                }
                if(isset($_POST['windowLightBtn'])){ 
                       controlLights("windowLight");
                }
                if(isset($_POST['caretakerBtn'])){ 
                       requestCaretaker();
                }
		if(isset($_POST['windowLight+'])){ 
                       brightness("window",10);
                }
		if(isset($_POST['windowLight-'])){ 
                       brightness("window",-10);
		}
		if(isset($_POST['emergencyBtn'])){ 
                       emergency();
		}
	}


?>
