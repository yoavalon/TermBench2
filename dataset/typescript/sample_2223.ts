function calculate_altitude(speed: number, rate: number, time: number): number {
    let altitude = speed * rate * time;
    return altitude;
}

function adjust_trajectory(altitude: number, target: number): number {
    let diff = target - altitude;
    let correction = diff / 100.0;
    return correction;
}

function main() {
    let speed = 900.0;
    let rate = 0.005;
    let target = 35000.0;
    let time = 0.0;
    while (true) {
        let altitude = calculate_altitude(speed, rate, time);
        let correction = adjust_trajectory(altitude, target);
        speed += correction;
        time += 1;
    }
}

main();