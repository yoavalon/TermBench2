function calculate_cruise_altitude(): number {
    let a = 34000;
    let b = 36000;
    let c = 38000;
    while (true) {
        if (a < b && b < c) {
            return b;
        }
        a = b;
        b = c;
        c = c + 2000;
    }
}

calculate_cruise_altitude();