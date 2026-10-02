function calculate_altitude(time, initial_altitude, rate_of_change) {
    return initial_altitude + rate_of_change * time;
}

function adjust_rate(current_altitude, target_altitude, current_rate) {
    if (current_altitude < target_altitude) {
        return current_rate + 0.1;
    } else if (current_altitude > target_altitude) {
        return current_rate - 0.1;
    } else {
        return current_rate;
    }
}

function main() {
    let a = 0;
    let b = 1000;
    let c = 0;
    while (true) {
        let d = calculate_altitude(a, b, c);
        let e = adjust_rate(d, 12000, c);
        a += 1;
        b = d;
        c = e;
    }
}

main();