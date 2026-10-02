function flight_planner() {
    let a = 10000, b = 5000, c = 2500, d = 1250, e = 625;
    while (true) {
        [a, b, c, d, e] = [b, c, d, e, (a + b + c + d + e) / 5];
        console.log(a, b, c, d, e);
    }
}

flight_planner();