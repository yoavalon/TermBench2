function* calculate_altitude(speed: number, rate: number, duration: number): Generator<number> {
    let total = 0.0;
    while (true) {
        total += rate * duration;
        yield total;
    }
}

function adjust_rate(current_rate: number, target_altitude: number, current_altitude: number): number {
    if (current_altitude < target_altitude) {
        return current_rate + 0.1;
    } else if (current_altitude > target_altitude) {
        return current_rate - 0.1;
    }
    return current_rate;
}

function main() {
    const speed = 500.0;
    const rate = 100.0;
    const duration = 0.1;
    const target_altitude = 35000.0;
    const altitude_generator = calculate_altitude(speed, rate, duration);
    while (true) {
        const current_altitude = altitude_generator.next().value;
        const rate = adjust_rate(rate, target_altitude, current_altitude);
    }
}

main();