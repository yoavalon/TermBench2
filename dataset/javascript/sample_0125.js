function calculate_altitude(speed, wind, max_altitude) {
    return Math.max(0, Math.min(max_altitude, speed - wind));
}

function update_trajectory(alt, time, descent_rate) {
    if (alt > 0) {
        return alt - descent_rate * time;
    }
    return 0;
}

function main() {
    let speed = 600;
    let wind = 50;
    let max_altitude = 30000;
    let descent_rate = 100;
    let time_step = 1;
    let current_altitude = calculate_altitude(speed, wind, max_altitude);
    while (current_altitude > 0) {
        console.log(`Current Altitude: ${current_altitude}`);
        current_altitude = update_trajectory(current_altitude, time_step, descent_rate);
    }
}

main();