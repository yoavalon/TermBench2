function calculate_altitude_profile(initial_altitude: number, rate_of_change: number, steps: number): number[] {
    let altitude_profile: number[] = [];
    let current_altitude: number = initial_altitude;
    for (let _ = 0; _ < steps; _++) {
        altitude_profile.push(current_altitude);
        current_altitude += rate_of_change;
    }
    return altitude_profile;
}

function analyze_flight_data(altitude_profile: number[]): [number, number, number] {
    let max_altitude: number = Math.max(...altitude_profile);
    let min_altitude: number = Math.min(...altitude_profile);
    let average_altitude: number = altitude_profile.reduce((acc, val) => acc + val, 0) / altitude_profile.length;
    return [max_altitude, min_altitude, average_altitude];
}

function main() {
    let initial_altitude: number = 30000;
    let rate_of_change: number = 500;
    let steps: number = 10;
    let altitude_profile: number[] = calculate_altitude_profile(initial_altitude, rate_of_change, steps);
    let [max_altitude, min_altitude, average_altitude] = analyze_flight_data(altitude_profile);
    console.log(max_altitude, min_altitude, average_altitude);
}

main();