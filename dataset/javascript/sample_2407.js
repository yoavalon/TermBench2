function calculate_altitude_profile(initial_alt, rate, steps) {
    let altitudes = [];
    let current_alt = initial_alt;
    for (let i = 0; i < steps; i++) {
        altitudes.push(current_alt);
        current_alt += rate;
    }
    return altitudes;
}
calculate_altitude_profile(3000, 500, 10);