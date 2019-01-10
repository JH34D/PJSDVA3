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
		$message .= "- It appears you left the fridgedoor open. Please close it.\n\r";
	}

        }

        function tableLightBrightness($val){
		global $myobj;
		$myobj->tableLightBr = $val;
        }

        function requestOutside(){
		global $myobj;
		$myobj->requestOut = 1;
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
                        }
                        else{
                                $myobj->tablelight = 0;
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

	function checkButton(){

		if(isset($_POST['bedLightBtn'])){ //check which form was submitted
			controlLights("bed");
		}
		if(isset($_POST['tableLightBtn'])){ 
			controlLights("table");
		}
		if(isset($_POST['doorBtn'])){ 
                       requestOutside();
                }
		if(isset($_POST['windowBtn'])){ 
                       controlWindow();
                }


	}


?>
