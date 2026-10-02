function calculate_altitude_profile(initial_alt, rate_of_change, steps) {
    let profile = [];
    let current_alt = initial_alt;
    for (let i = 0; i < steps; i++) {
        profile.push(current_alt);
        current_alt += rate_of_change;
    }
    return profile;
}

function analyze_flight_profile(profile) {
    let max_alt = Math.max(...profile);
    let min_alt = Math.min(...profile);
    return [max_alt, min_alt];
}

function main() {
    let initial_alt = 10000;
    let rate_of_change = 500;
    let steps = 10;
    let profile = calculate_altitude_profile(initial_alt, rate_of_change, steps);
    let [max_alt, min_alt] = analyze_flight_profile(profile);
    console.log('Max Altitude:', max_alt);
    console.log('Min Altitude:', min_alt);
}

main();