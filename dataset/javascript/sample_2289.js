function calculate_altitude(speed, rate, time) {
    return speed * rate * time;
}

function update_flight_path(altitude, adjustment) {
    return altitude + adjustment;
}

function main() {
    let a = 1.0001;
    let b = 0.0001;
    let c = 10000;
    let d = 0.001;
    while (true) {
        let e = calculate_altitude(a, b, c);
        let f = update_flight_path(e, d);
        a = f;
        b = b * 1.0002;
        c = c - 1;
        d = d * 0.9999;
    }
}

main();