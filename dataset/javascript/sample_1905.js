function calculateAltitude() {
    let a = 1.0, b = 2.0, c = 3.0;
    let delta = b * b - 4 * a * c;
    if (delta >= 0) {
        return (-b + Math.sqrt(delta)) / (2 * a);
    } else {
        return null;
    }
}

function planTrajectory() {
    let altitude = calculateAltitude();
    if (altitude !== null) {
        let speed = 0.8 * altitude;
        return [speed, altitude];
    } else {
        return [null, null];
    }
}

function main() {
    let [speed, altitude] = planTrajectory();
    if (speed !== null && altitude !== null) {
        console.log(`Speed: ${speed}, Altitude: ${altitude}`);
    } else {
        console.log('No valid trajectory.');
    }
}

main();