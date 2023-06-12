# Created by Lucas Fernando - 22th April 2023
# Feel free to modify this code the way you want and need.

def getValue():
    sensorValue = 0
    for i in range(20):
        sensorValue += sensor.read()
        
    sensorValue = int(sensorValue / 20) 
    print(f"Value: {sensorValue}")
    return sensorValue
    

def website(sensorValue):
    if sensorValue < 300:
        content = """
                    <div id="no-danger" class="card" style="width: 18rem;">
                        <div class="card-body">
                            <h5 class="card-title">No danger</h5>
                            <p class="card-text">The water level is low. There will be no dangerous situation happening soon.</p>
                        </div>
                    </div>
                  """
    elif sensorValue >= 300 and sensorValue < 1000:
        content = """
                    <div id="caution" class="card" style="width: 18rem;">
                        <div class="card-body">
                            <h5 class="card-title">Caution</h5>
                            <p class="card-text">The water level is above the safe point. Stay aware to dangerous situations.</p>
                        </div>
                    </div>
                  """
    elif sensorValue >= 1000 and sensorValue < 1400:
        content = """
                    <div id="danger" class="card" style="width: 18rem;">
                        <div class="card-body">
                            <h5 class="card-title">Danger</h5>
                            <p class="card-text">The water level is too high. A dangerous situation has begun.</p>
                        </div>
                    </div>
                  """
    else:
        content = """
                    <div id="critical" class="card" style="width: 18rem;">
                        <div class="card-body">
                            <h5 class="card-title">Critical</h5>
                            <p class="card-text">The water level is at its highest point. There's no way to stop the dangerous situation now.</p>
                        </div>
                    </div>
                  """
        
    page = """
            <!DOCTYPE html>
            <html>
                <head>
                    <meta charset="utf-8">
                    <meta http-equiv="refresh" content="2">
                    <meta name="viewport" content="width=device-width, initial-scale=1.0">
                    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-rbsA2VBKQhggwzxH7pPCaAqO46MgnOM80zW1RWuH61DGLwZJEdK2Kadq2F9CUG65" crossorigin="anonymous">
                    <style>
                        html, body {
                            display: flex;
                            flex-direction: column;
                            margin: 0;
                            min-height: 100vh;
                            padding: 0;
                        }
                        
                        #title {
                            padding: 100px 0 100px 0;
                        }
                        
                        h1, h2 {
                            text-align: center;
                        }
                        
                        .card {
                            /* Centralize cards */
                            border-radius: 10px;
                            color: #ffffff;
                            float: none;
                            margin: 0 auto;
                        }
                        
                        #no-danger {
                            background-color: #13034B;
                            border: solid 4px #13034B;
                            
                        }
                        
                        #caution {
                            background-color:  #B85207;
                            border: solid 4px  #B85207;
                        }
                        
                        #danger {
                            background-color: #880808;
                            border: solid 4px  #880808;
                        }
                        
                        #critical {
                            background-color: #581845;
                            border: solid 4px #581845;
                        }
                        
                        footer {
                            background-color: #313133;
                            color: #FFFFFF;
                            margin-top: auto;
                            padding: 30px;
                        }
                    </style>
                    <title>Water level</title>
                </head>
                <body>
                    <main>
                        <div class="container-fluid">
                            <div id="title" class="row">
                                <hgroup>
                                    <h1>Water level</h1>
                                    <h2>Keep up with the water level</h2>
                                </hgroup>
                            </div>
                        </div>
                        <div class="container">
                            <div class="row">""" + content + """</div>
                        </div>
                    </main>
                    <footer class="text-center">
                        <div class="text-center">
                            Created by <a href="https://www.youtube.com/channel/UCSSe6BNfjB_yVbk8yL-he8w" target="_blank">Lucas Fernando</a>. Feel free to use it and modify the way you want. This page code is available on <a href="https://github.com/LucasFernandoChannel/water-level" target="_blank">Github</a>.
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
    
    sensorValue = getValue()
    response = website(sensorValue)
    
    conn.send("HTTP/1.1 200 OK\n")
    conn.send("Content-Type: text/html\n")
    conn.send("Connection: close\n\n")
    conn.sendall(response)
    conn.close()
    
