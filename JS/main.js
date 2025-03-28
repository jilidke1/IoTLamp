const endpoint = "http://192.168.1.9";

function getdapurled(){
    fetch(endpoint + "/dapur",{
        method:  "GET"
    }).then(response => response.text()).then(result => {
        if(result == "ON"){
            ledDapur.style.backgroundColor = "blue";
            ledDapurimg.src = "./Assets/led-on.png";
            ledDapurSpan.textContent = "OFF";
        }else{
            ledDapur.style.backgroundColor = "#579fff";
            ledDapurimg.src = "./Assets/led-off.png";
            ledDapurSpan.textContent = "ON";
        }
    });
}

function gettamuled(){
    fetch(endpoint + "/tamu",{
        method:  "GET"
    }).then(response => response.text()).then(result => {
        if(result == "ON"){
            ledTamu.style.backgroundColor = "blue";
            ledTamuimg.src = "./Assets/led-on.png";
             ledTamuSpan.textContent = "OFF";
        }else{
            ledTamu.style.backgroundColor = "#579fff";
            ledTamuimg.src = "./Assets/led-off.png";
            ledTamuSpan.textContent = "ON";
        }
    });
}

function getmakanled(){
    fetch(endpoint + "/makan",{
        method:  "GET"
    }).then(response => response.text()).then(result => {
        if(result == "ON"){
            ledMakan.style.backgroundColor = "blue";
            ledMakanimg.src = "./Assets/led-on.png";
            ledMakanSpan.textContent = "OFF";
        }else{
            ledMakan.style.backgroundColor = "#579fff";
            ledMakanimg.src = "./Assets/led-off.png";
            ledMakanSpan.textContent = "ON";
        }
    });
}

function getkamarled(){
    fetch(endpoint + "/kamar",{
        method:  "GET"
    }).then(response => response.text()).then(result => {
        if(result == "ON"){
            ledKamar.style.backgroundColor = "blue";
            ledKamarimg.src = "./Assets/led-on.png";
            ledKamarSpan.textContent = "OFF";
        }else{
            ledKamar.style.backgroundColor = "#579fff";
            ledKamarimg.src = "./Assets/led-off.png";
            ledKamarSpan.textContent = "ON";
        }
    });
}

function SetDapurLed(){
    fetch(endpoint + "/dapur",{
        method:  "POST"
    }).then(response => response.text()).then(()=> location.reload());
}

function SetTamuLed(){
    fetch(endpoint + "/tamu",{
        method:  "POST"
    }).then(response => response.text()).then(()=> location.reload());
}

function SetMakanLed(){
    fetch(endpoint + "/makan",{
        method:  "POST"
    }).then(response => response.text()).then(()=> location.reload());
}

function SetKamarLed(){
    fetch(endpoint + "/kamar",{
        method:  "POST"
    }).then(response => response.text()).then(()=> location.reload());
}


getdapurled();
gettamuled();
getmakanled();
getkamarled();