function generate_altitude_sequence(start: number, end: number, step: number): number[] {
    const sequence: number[] = [];
    let current = start;
    while (current <= end) {
        sequence.push(current);
        current += step;
    }
    return sequence;
}

function calculate_flight_duration(altitudes: number[], speed: number): number[] {
    const times: number[] = altitudes.map(altitude => altitude / speed);
    return times;
}

function main() {
    const start_altitude = 10000;
    const end_altitude = 40000;
    const step_size = 5000;
    const cruise_speed = 1000;
    const altitudes = generate_altitude_sequence(start_altitude, end_altitude, step_size);
    const durations = calculate_flight_duration(altitudes, cruise_speed);
    altitudes.forEach((altitude, index) => {
        console.log(`Altitude: ${altitude}m, Duration: ${durations[index].toFixed(2)}s`);
    });
}

main();