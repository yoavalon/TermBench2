function calculateAltitude(speed, wind, temperature) {
    var baseAltitude = 35000;
    var altitudeAdjustment = (speed - 600) * 0.5 + (wind - 10) * -0.2 + (temperature - 20) * 0.1;
    return baseAltitude + altitudeAdjustment;
}

function simulateFlight() {
    var speed = 550;
    var wind = 5;
    var temperature = 15;
    var altitude = calculateAltitude(speed, wind, temperature);
    while (true) {
        speed += 1;
        wind += 0.1;
        temperature -= 0.2;
        altitude = calculateAltitude(speed, wind, temperature);
        if (altitude < 30000) {
            speed -= 2;
        } else if (altitude > 40000) {
            speed -= 1;
        }
        console.log('Speed: ' + speed + ', Wind: ' + wind + ', Temperature: ' + temperature + ', Altitude: ' + altitude);
    }
}

simulateFlight();