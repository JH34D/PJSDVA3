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
      border-radius: 10px;
    }
    .row::after {
      content: "";
      clear: both;
      display: table;
    }
    </style>
  </head>
  <body>
    <div class="row">
      <div class="col-2"><h3>Bed Light</h3></div>
      <div class="col-2"><h3>Door Light</h3></div>
      <div class="col-2"><h3>Lamp Light</h3></div>
      <div class="col-2"><h3>LED-strip lights</h3></div>
    </div>
    <div class="row">
      <div class="col-2"><img src="LightOff.png" alt="Operate Bed Light Off"></div>
      <div class="col-2"><img src="LightOn.png" alt="Operate Door Light On"></div>
      <div class="col-2"><img src="LightOff.png" alt="Operate Lamp Light Off"></div>
      <div class="col-1">
        <img src="six.png" style="padding-bottom:7%">
        </br>
        <img src="four.png">
      </div>
      <div class="col-1">
        <img src="seven.png" style="padding-bottom:7%">
        </br>
        <img src="five.png">
      </div>
    </div>
    <div class="row">
      <div class="col-2"><img src="BlindsClosed.png" alt="Operate Blinds Closed"></div>
      <div class="col-2"><img src="Staff.png" alt="Call Staff"></div>
      <div class="col-2"><img src="Emergency.png" alt="Emergency"></div>
      <div class="col-1">
        <img src="two.png" style="padding-bottom:7%">
        </br>
        <img src="zero.png">
      </div>
      <div class="col-1">
        <img src="three.png" style="padding-bottom:7%">
        </br>
        <img src="one.png">
      </div>
    </div>
  </body>
</html>


