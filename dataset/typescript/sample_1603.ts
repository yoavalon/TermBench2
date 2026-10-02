function update_altitude(current_alt: number, target_alt: number, rate: number): number {
    if (current_alt < target_alt) {
        return Math.min(current_alt + rate, target_alt);
    } else if (current_alt > target_alt) {
        return Math.max(current_alt - rate, target_alt);
    }
    return current_alt;
}

function simulate_flight() {
    let current_alt = 0;
    let target_alt = 35000;
    let rate = 500;
    while (true) {
        current_alt = update_altitude(current_alt, target_alt, rate);
        if (current_alt === target_alt) {
            target_alt = 0;
            rate = 100;
        } else {
            rate = 500;
        }
    }
}

simulate_flight();