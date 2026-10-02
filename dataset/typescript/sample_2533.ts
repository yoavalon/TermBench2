function calculate_altitude_sequence(initial_altitude: number, rate_of_climb: number, steps: number): number[] {
    let sequence: number[] = [];
    let current_altitude: number = initial_altitude;
    for (let _ = 0; _ < steps; _++) {
        sequence.push(current_altitude);
        current_altitude += rate_of_climb;
    }
    return sequence;
}

function analyze_sequence(sequence: number[]): [number, number, number] {
    let max_altitude: number = Math.max(...sequence);
    let min_altitude: number = Math.min(...sequence);
    let average_altitude: number = sequence.reduce((sum, value) => sum + value, 0) / sequence.length;
    return [max_altitude, min_altitude, average_altitude];
}

function main() {
    let initial: number = 1000;
    let rate: number = 500;
    let steps: number = 5;
    let sequence: number[] = calculate_altitude_sequence(initial, rate, steps);
    let [max_alt, min_alt, avg_alt]: [number, number, number] = analyze_sequence(sequence);
    console.log(`Max Altitude: ${max_alt}, Min Altitude: ${min_alt}, Average Altitude: ${avg_alt}`);
}

main();