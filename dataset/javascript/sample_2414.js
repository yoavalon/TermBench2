function calculate_flight_altitude(max_alt, rate, steps) {
    let altitudes = [];
    let current_alt = 0;
    for (let i = 0; i < steps; i++) {
        current_alt += rate;
        if (current_alt > max_alt) {
            altitudes.push(max_alt);
            break;
        }
        altitudes.push(current_alt);
    }
    return altitudes;
}

let result = calculate_flight_altitude(30000, 1000, 20);
console.log(result);