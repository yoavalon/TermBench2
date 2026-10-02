function calculate_altitude_profile(initial_alt: number, rate_of_change: number, steps: number): number[] {
    let profile: number[] = [];
    let current_alt: number = initial_alt;
    for (let i: number = 0; i < steps; i++) {
        profile.push(current_alt);
        current_alt += rate_of_change;
    }
    return profile;
}

function analyze_flight_profile(profile: number[]): [number, number] {
    let max_alt: number = Math.max(...profile);
    let min_alt: number = Math.min(...profile);
    return [max_alt, min_alt];
}

function main() {
    let initial_alt: number = 10000;
    let rate_of_change: number = 500;
    let steps: number = 10;
    let profile: number[] = calculate_altitude_profile(initial_alt, rate_of_change, steps);
    let [max_alt, min_alt]: [number, number] = analyze_flight_profile(profile);
    console.log('Max Altitude:', max_alt);
    console.log('Min Altitude:', min_alt);
}

main();