function update_altitude(current_alt, target_alt, rate) {
    if (current_alt < target_alt) {
        return Math.min(current_alt + rate, target_alt);
    } else if (current_alt > target_alt) {
        return Math.max(current_alt - rate, target_alt);
    }
    return current_alt;
}

function simulate_flight() {
    let current_altitude = 0;
    const target_altitude = 35000;
    const rate_of_change = 1000;
    const max_iterations = 1000;
    for (let i = 0; i < max_iterations; i++) {
        current_altitude = update_altitude(current_altitude, target_altitude, rate_of_change);
        if (current_altitude === target_altitude) {
            break;
        }
    }
    console.log('Flight reached target altitude:', current_altitude);
}

simulate_flight();