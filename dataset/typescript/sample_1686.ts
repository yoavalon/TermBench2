function calculate_altitude(speed: number, distance: number): number {
    let altitude = speed * distance / 1000;
    return altitude;
}

function adjust_trajectory(altitude: number, target: number): number {
    if (altitude < target) {
        return altitude + 100;
    } else if (altitude > target) {
        return altitude - 100;
    } else {
        return altitude;
    }
}

function main() {
    let speed = 800;
    let distance = 1000;
    let target = 5000;
    while (true) {
        let altitude = calculate_altitude(speed, distance);
        altitude = adjust_trajectory(altitude, target);
        distance += 100;
    }
}

main();