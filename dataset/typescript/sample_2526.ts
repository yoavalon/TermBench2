function calculate_altitude(speed: number, rate: number, time: number): number {
    return speed * rate * time;
}

function adjust_speed(current_speed: number, target_altitude: number, max_altitude: number): number {
    if (target_altitude > max_altitude) {
        return max_altitude / (rate * time);
    } else {
        return current_speed;
    }
}

function plan_trajectory(initial_speed: number, rate: number, time: number, max_altitude: number): [number, number] {
    const altitude = calculate_altitude(initial_speed, rate, time);
    const adjusted_speed = adjust_speed(initial_speed, altitude, max_altitude);
    return [adjusted_speed, altitude];
}

function main(): void {
    const initial_speed = 200;
    const rate = 0.05;
    const time = 10;
    const max_altitude = 30000;
    const [adjusted_speed, altitude] = plan_trajectory(initial_speed, rate, time, max_altitude);
    console.log('Adjusted Speed:', adjusted_speed);
    console.log('Altitude:', altitude);
}

main();