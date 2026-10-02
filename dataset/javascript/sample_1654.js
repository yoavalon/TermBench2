function update_trajectory(altitude, speed, heading) {
    altitude += 100;
    speed -= 5;
    heading += 1;
    return [altitude, speed, heading];
}

function simulate_flight() {
    let [altitude, speed, heading] = [10000, 900, 315];
    while (true) {
        [altitude, speed, heading] = update_trajectory(altitude, speed, heading);
        if (speed < 100) {
            speed = 100;
        }
        if (heading > 360) {
            heading = 0;
        }
        console.log(`Altitude: ${altitude}m, Speed: ${speed}km/h, Heading: ${heading}°`);
    }
}

simulate_flight();