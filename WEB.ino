void connectToWifi() {
  Serial.print("Connecting to ");
  Serial.print(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}
void handleTheRequest(WiFiClient client) {
  String pasword, value;
  request = client.readStringUntil('\r');
  Serial.println(request);
  value = request.substring(19, -1);
  if (request.indexOf("/newpage?value") != -1) {
    if (value.indexOf(my_password) != -1) {
      flag_fun = 1;
      olde("ready for action");
    } else if (value.indexOf("left") != -1) {
      flag_fun = 2;
    } else if (value.indexOf("right") != -1) {
      flag_fun = 3;
    } else if (value.indexOf("up") != -1) {
      flag_fun = 4;
    } else if (value.indexOf("down") != -1) {
      flag_fun = 5;
    } else if (value.indexOf("center") != -1) {
      flag_fun = 6;
    }
  }
}

void enterPassword(WiFiClient client) {
  String my_html;
  client.println("<!DOCTYPE html>");
  client.println("<html lang=\"iw\">");
  client.println("<head>");
  client.println("    <meta charset=\"UTF-8\">");
  client.println("    <meta name=\"viewport\" content=\"width=device-width\">");
  client.println("    <title>הסיסמה שלי</title>");
  client.println("    <style>");
  client.println("        body {");
  client.println("            font-family: 'Arial', sans-serif;");
  client.println("            background-color: #f0f0f0;");
  client.println("            margin: 0;");
  client.println("            padding: 0;");
  client.println("            display: flex;");
  client.println("            justify-content: center;");
  client.println("            align-items: center;");
  client.println("            height: 100vh;");
  client.println("        }");
  client.println("        .container {");
  client.println("            background-color: #fff;");
  client.println("            border-radius: 10px;");
  client.println("            box-shadow: 0 0 20px rgba(0, 0, 0, 0.1);");
  client.println("            padding: 20px;");
  client.println("            max-width: 400px;");
  client.println("            width: 100%;");
  client.println("            text-align: center;");
  client.println("        }");
  client.println("        .form-group {");
  client.println("            margin-bottom: 15px;");
  client.println("        }");
  client.println("        label {");
  client.println("            display: block;");
  client.println("            font-size: 1.2em;");
  client.println("            margin-bottom: 8px;");
  client.println("        }");
  client.println("        input[type=\"text\"] {");
  client.println("            width: 100%;");
  client.println("            padding: 10px;");
  client.println("            border: 1px solid #ccc;");
  client.println("            border-radius: 5px;");
  client.println("            box-sizing: border-box;");
  client.println("            font-size: 1em;");
  client.println("        }");
  client.println("        .custom-button {");
  client.println("            background-color: #1E90FF;");
  client.println("            color: white;");
  client.println("            padding: 10px 20px;");
  client.println("            border: none;");
  client.println("            border-radius: 5px;");
  client.println("            font-size: 1em;");
  client.println("            cursor: pointer;");
  client.println("            transition: background-color 0.3s;");
  client.println("            margin-top: 5px;");
  client.println("        }");
  client.println("        .custom-button:hover {");
  client.println("            background-color: #0056b3;");
  client.println("        }");
  client.println("        .send {");
  client.println("            font-size: 1.1em;");
  client.println("            color: #333;");
  client.println("            margin-top: 20px;");
  client.println("        }");
  client.println("        @media (max-width: 600px) {");
  client.println("            .container {");
  client.println("                padding: 15px;");
  client.println("            }");
  client.println("            label {");
  client.println("                font-size: 1em;");
  client.println("            }");
  client.println("            input[type=\"text\"],");
  client.println("            .custom-button {");
  client.println("                font-size: 0.9em;");
  client.println("            }");
  client.println("        }");
  client.println("    </style>");
  client.println("    <script>");
  client.println("        function getValueAndRedirect() {");
  client.println("            var textBoxValue = document.getElementById(\"thesis\").value;");
  client.println("            var encodedValue = encodeURIComponent(textBoxValue);");
  client.println("            location.href = \"/newpage?value=\" + encodedValue;");
  client.println("        }");
  client.println("    </script>");
  client.println("</head>");
  client.println("<body>");
  client.println("    <div class=\"container\">");
  client.println("        <div class=\"form-group\">");
  client.println("            <label for=\"thesis\">Enter a password</label>");
  client.println("            <input type=\"text\" id=\"thesis\" placeholder=\"password\">");
  client.println("            <button class=\"custom-button\" onclick=\"getValueAndRedirect()\">log in</button>");
  client.println("        </div>");
  client.println("        <div class=\"form-group\">");
  client.println("            <p class=\"send\">");
  client.println("                <!-- כאן יש להוסיף את ההודעה שאתה רוצה להציג -->");
  client.println("            </p>");
  client.println("        </div>");
  client.println("    </div>");
  client.println("</body>");
  client.println("</html>");
}

void navigation(WiFiClient client) {
  String my_html;
  client.println("<!DOCTYPE html>");
  client.println("<html lang=\"en\">");
  client.println("<head>");
  client.println("<meta charset=\"UTF-8\">");
  client.println("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">");
  client.println("<title>Directional Control</title>");
  client.println("<style>");
  client.println("body { display: flex; flex-direction: column; align-items: center; justify-content: center; height: 100vh; margin: 0; background-color: #f0f0f0; font-family: Arial, sans-serif; }");
  client.println(".camera-container, .control-container { display: flex; justify-content: center; align-items: center; margin-bottom: 20px; background-color: #fff; padding: 20px; border-radius: 10px; box-shadow: 0 4px 8px rgba(0, 0, 0, 0.2); }");
  client.println(".camera-container { position: relative; padding: 10px 40px; }");
  client.println(".camera { font-size: 24px; font-weight: bold; color: #1E90FF; }");
  client.println(".arrow { width: 0; height: 0; border-style: solid; position: absolute; }");
  client.println(".arrow-left { border-width: 15px 15px 15px 0; border-color: transparent #1E90FF transparent transparent; left: -30px; }");
  client.println(".arrow-right { border-width: 15px 0 15px 15px; border-color: transparent transparent transparent #1E90FF; right: -30px; }");
  client.println(".control-container { flex-direction: column; align-items: center; }");
  client.println(".control-row { display: flex; justify-content: center; margin: 5px 0; }");
  client.println(".control { width: 50px; height: 50px; background-color: #1E90FF; color: white; text-align: center; line-height: 50px; margin: 5px; cursor: pointer; border-radius: 5px; transition: background-color 0.3s ease; border: none; }");
  client.println(".control:hover { background-color: darkblue; }");
  client.println("</style>");
  client.println("</head>");
  client.println("<body>");
  client.println("<div class=\"camera-container\">");
  // client.println("<button class=\"arrow arrow-left\" onclick=\"change('camLeft')\"></button>");
  client.println("<img src=\"http://192.168.0.101:81/stream\">");
  // client.println("<button class=\"arrow arrow-right\" onclick=\"change('camRight')\"></button>");
  client.println("</div>");
  client.println("<div class=\"control-container\">");
  client.println("<div class=\"control-row\">");
  client.println("<button class=\"control\" onclick=\"change('up')\">↑</button>");
  client.println("</div>");
  client.println("<div class=\"control-row\">");
  client.println("<button class=\"control\" onclick=\"change('left')\">←</button>");
  client.println("<button class=\"control\" onclick=\"change('center')\">●</button>");
  client.println("<button class=\"control\" onclick=\"change('right')\">→</button>");
  client.println("</div>");
  client.println("<div class=\"control-row\">");
  client.println("<button class=\"control\" onclick=\"change('down')\">↓</button>");
  client.println("</div>");
  client.println("</div>");
  client.println("<script>");
  client.println("function change(value) { location.href = \"/newpage?value=\" + value; }");
  client.println("</script>");
  client.println("</body>");
  client.println("</html>");
}

void web() {
  client = server.available();
  if (client) {
    String my_html;
    handleTheRequest(client);  // Read the request
    if (flag_fun == 0) {
      enterPassword(client);
    } else {
      navigation(client);
    }
    client.stop();
    Serial.println("Client disconnected.");
  }
}
