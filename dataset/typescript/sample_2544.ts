function calculate_altitude_sequence(initial_altitude: number, increment: number, steps: number): number[] {
    const sequence: number[] = [];
    for (let i = 0; i < steps; i++) {
        sequence.push(initial_altitude + i * increment);
    }
    return sequence;
}

function find_optimal_cruise_altitude(altitudes: number[], max_fuel_consumption: number): number {
    let optimal_altitude = altitudes[0];
    for (const altitude of altitudes) {
        if (altitude <= max_fuel_consumption && altitude > optimal_altitude) {
            optimal_altitude = altitude;
        }
    }
    return optimal_altitude;
}

function main() {
    const initial = 10000;
    const increment = 1000;
    const steps = 10;
    const max_fuel = 15000;
    const altitudes = calculate_altitude_sequence(initial, increment, steps);
    const optimal_altitude = find_optimal_cruise_altitude(altitudes, max_fuel);
    console.log(optimal_altitude);
}

main();