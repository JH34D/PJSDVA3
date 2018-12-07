<!DOCTYPE html>
<html>
  <head>
    <title>Opening page</title>
    <style type="text/css">
      body,html {
        padding: 3px 3px 3px 3px;

        background-color: #D8DBE2;

        font-family: Arial, sans-serif;
        font-size: 11pt;
        text-align: center;
      }
      h1 {
        font-size: 60pt;
      }
    </style>
  </head>
  <body>
    <script>
      function getin() {
        var tested = 1;
        var prompt1 = prompt('Please enter your PIN code','');
        while (tested < 3) {
          if (!prompt1)
            history.go(-1);
          if (prompt1 == "1111") {
            window.open('hank.php');
            break;
          } else if (prompt1 == "2222") {
            window.open('porter.php');
            break;
          } else if (prompt1 == "3333") {
            window.open('medic.php');
            break;
          }
          testV+=1;
          var prompt1 = prompt('Incorrect PIN code. Please try again','');
        }
        if (prompt1 != "1111" & prompt1 != "2222" & prompt1 != "3333" & tested == 3)
          history.go(-1);
          return "";
      }
    </script>
    <form>
    <input type="button" value="Click me to enter the protected pages" onClick="getin()">
  </body>
</html>


