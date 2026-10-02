function update_trajectory(altitude: number, speed: number, heading: number): [number, number, number] {
    altitude += 100;
    speed -= 5;
    heading += 1;
    return [altitude, speed, heading];
}

function simulate_flight(): void {
    let altitude = 10000;
    let speed = 900;
    let heading = 315;
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