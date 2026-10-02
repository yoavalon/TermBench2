function calculate_altitude(speed: number, rate: number): number {
    return speed * rate;
}

function adjust_altitude(current: number, target: number): number {
    let difference = target - current;
    let correction = difference * 0.1;
    return current + correction;
}

function main(): void {
    let initial_speed = 500.5;
    let rate = 0.8;
    let target_altitude = 45000.0;
    let current_altitude = 0.0;
    for (let _ = 0; _ < 100; _++) {
        current_altitude = calculate_altitude(initial_speed, rate);
        current_altitude = adjust_altitude(current_altitude, target_altitude);
        if (Math.abs(current_altitude - target_altitude) < 100) {
            break;
        }
    }
    console.log(current_altitude);
}

main();