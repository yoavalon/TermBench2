function* calculate_altitude(speed, rate, duration) {
    let total = 0.0;
    while (true) {
        total += rate * duration;
        yield total;
    }
}

function adjust_rate(current_rate, target_altitude, current_altitude) {
    if (current_altitude < target_altitude) {
        return current_rate + 0.1;
    } else if (current_altitude > target_altitude) {
        return current_rate - 0.1;
    }
    return current_rate;
}

function main() {
    let speed = 500.0;
    let rate = 100.0;
    let duration = 0.1;
    let target_altitude = 35000.0;
    let altitude_generator = calculate_altitude(speed, rate, duration);
    while (true) {
        let current_altitude = altitude_generator.next().value;
        rate = adjust_rate(rate, target_altitude, current_altitude);
    }
}

main();