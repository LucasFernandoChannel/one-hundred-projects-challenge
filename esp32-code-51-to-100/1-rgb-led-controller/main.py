# Project #1 - RGB LED controller
# This code is part of the challenge 100 Arduino and ESP32 projects.
# You can find more information about this initiative at https://github.com/LucasFernandoChannel/one-hundred-projects-challenge
# Created by Lucas Fernando - check my Youtube channel at https://www.youtube.com/@lucasfernandochannel

def website():
    if redLed.value() == 1:
        redState = "ON"
    else:
        redState = "OFF"
        
    if greenLed.value() == 1:
        greenState = "ON"
    else:
        greenState = "OFF"
        
    if blueLed.value() == 1:
        blueState = "ON"
    else:
        blueState = "OFF"
        
    page = """
            <!DOCTYPE html>
            <html>
                <head>
                    <meta charset="utf-8">
                    <meta name="viewport" content="width=device-width, initial-scale=1.0">
                    <title>
                        RGB Led Controller
                    </title>
                    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-rbsA2VBKQhggwzxH7pPCaAqO46MgnOM80zW1RWuH61DGLwZJEdK2Kadq2F9CUG65" crossorigin="anonymous">
                    <style>
                        html, body {
                            background-color: #ffffff;
                            display: flex;
                            flex-direction: column;
                            margin: 0;
                            min-height: 100vh;
                            padding: 0;
                        }
                        
                        hgroup {
                            margin: 0;
                            padding: 0;
                        }
                        
                        h1, h2 {
                            text-align: center;
                        }
                        
                        #title {
                            margin: 100px 0 100px 0;
                        }
                        
                        .card {
                            /* Centralize cards */
                            border-radius: 10px;
                            float: none;
                            margin: 0 auto;
                            margin-bottom: 40px;
                        }
                        
                        #redCard {
                            border: 4px solid #dc3545;
                        }
                        
                        #greenCard {
                            border: 4px solid #28a745;
                        }
                        
                        #blueCard {
                            border: 4px solid #007bff;
                        }
                        
                        footer {
                            margin-top: auto;
                        }
                    </style>
                </head>
                <body>
                    <main>
                        <div id="title" class="container-fluid">
                            <div class="row">
                                <hgroup>
                                    <h1>
                                        RGB Led Controller
                                    </h1>
                                    <h2>
                                        Use this page to control your RGB led remotely.
                                    </h2>
                                </hgroup>
                            </div>
                        </div>
                        <div class="container">
                            <div class="row">
                                <div id="redCard" class="card" style="width: 18rem;">
                                    <div class="card-body">
                                        <h5 class="card-title">Red light</h5>
                                        <p class="card-text">Use the button bellow to turn on and off the red light of your RGB led.</p>
                                        <a href="/?red" class="btn btn-danger">""" + redState + """</a>
                                    </div>
                                </div>
                                <div id="greenCard" class="card" style="width: 18rem;">
                                    <div class="card-body">
                                        <h5 class="card-title">Green light</h5>
                                        <p class="card-text">Use the button bellow to turn on and off the green light of your RGB led.</p>
                                        <a href="/?green" class="btn btn-success">""" + greenState + """</a>
                                    </div>
                                </div>
                                <div id="blueCard" class="card" style="width: 18rem;">
                                    <div class="card-body">
                                        <h5 class="card-title">Blue light</h5>
                                        <p class="card-text">Use the button bellow to turn on and off the blue light of your RGB led.</p>
                                        <a href="/?blue" class="btn btn-primary">""" + blueState + """</a>
                                    </div>
                                </div>
                            </div>
                        </div>
                    </main>
                    <footer class="bg-dark text-center">
                        <div class="text-center text-light p-3">
                            Created by <a href="https://www.youtube.com/channel/UCSSe6BNfjB_yVbk8yL-he8w" target="_blank">Lucas Fernando</a>. Feel free to use it and modify the way you want. This page code is available on <a href="https://github.com/LucasFernandoChannel/rgb-led-controller" target="_blank">Github</a>.
                        </div>
                    </footer>
                    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-kenU1KFdBIe4zVF0s0G1M5b4hcpxyD9F7jL+jjXkk+Q2h455rYXK/7HAuoJl+0I4" crossorigin="anonymous"></script>
                </body>
            </html>
           """
    
    return page


server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(('', 80))
server.listen(5)

while True:
    conn, addr = server.accept()
    print(f"The server got a connection from {str(addr)}")
    request = conn.recv(1024)
    request = str(request)
  
    red = request.find("/?red")
    green = request.find("/?green")
    blue = request.find("/?blue")
  
    if (red == 6):
        if redLed.value() == 1:
            redLed.value(0)
        else:
            redLed.value(1)
        
    if (green == 6):
        if greenLed.value() == 1:
            greenLed.value(0)
        else:
            greenLed.value(1)
        
    if (blue == 6):
        if blueLed.value() == 1:
            blueLed.value(0)
        else:
            blueLed.value(1)
            
    response = website()
    conn.send("HTTP/1.1 200 OK\n")
    conn.send("Content-Type: text/html\n")
    conn.send("Connection: close\n\n")
    conn.sendall(response)
    conn.close()
    
