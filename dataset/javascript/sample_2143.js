function flight_altitude_planning() {
    let a = 36000.0;
    let b = 10.0;
    let c = 0.001;
    let i = 0;
    while (true) {
        a += b * c;
        b -= c;
        c *= 2;
        i += 1;
        if (i % 1000 === 0) {
            console.log(a, b, c);
        }
    }
}

flight_altitude_planning();