function calculate_altitude(speed: number, wind: number, max_altitude: number): number {
    return Math.max(0, Math.min(max_altitude, speed - wind));
}

function update_trajectory(alt: number, time: number, descent_rate: number): number {
    if (alt > 0) {
        return alt - descent_rate * time;
    }
    return 0;
}

function main() {
    const speed = 600;
    const wind = 50;
    const max_altitude = 30000;
    const descent_rate = 100;
    const time_step = 1;
    let current_altitude = calculate_altitude(speed, wind, max_altitude);
    while (current_altitude > 0) {
        console.log(`Current Altitude: ${current_altitude}`);
        current_altitude = update_trajectory(current_altitude, time_step, descent_rate);
    }
}

main();