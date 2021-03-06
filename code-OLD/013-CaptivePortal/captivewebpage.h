const char captiveWebpage[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en" class="">
<head>
<meta charset='utf-8'>
<meta name="viewport" content="width=device-width,initial-scale=1,user-scalable=no"/>
<title>
Tasmota - Console</title>
<style>
body {
  font-family: Verdana, sans-serif;
  text-align: center;
  background: #222;
  color: #fff;
  line-height: 200%;
  margin: 0;
}
hr {
  border-color: #666;
}
button {
  background: #333;
  color: #fff;
  font-family: Verdana, sans-serif;
  border: 0.3ch solid #333;
  display: inline-block;
  font-size: 20px;
  margin: 8px;
  margin-top: 12px;
}
.helpB {
  text-align: left;
  position: absolute;
  width: 60px;
}
input {
  background: #333;
  color: #fff;
  font-family: Verdana, sans-serif;
  border: 0.5ch solid #333;
}
input[type="number"] {
  width: 4em;
}
select {
  background: #333;
  color: #fff;
  font-family: Verdana, sans-serif;
  border: 0.5ch solid #333;
}
td {
  padding: 2px;
}
.d5 {
  width: 4.5em !important;
}
</style>
<head>
<body>
<form id="form_s" name="Sf" method="post">
    <h2>WiFi setup</h2>
    <h3>Connect to existing network</h3>
    Network name (SSID, empty to not connect): <br><input name="CS" maxlength="32"><br>
    Network password: <br> <input type="password" name="CP" maxlength="63"><br>
    <hr>
    <button type="submit">Save & Connect</button>
  </form>
</body>
</html>
)rawliteral";
