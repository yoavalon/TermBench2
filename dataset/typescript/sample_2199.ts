function flight_altitude_planning() {
    let a = 0.0001, b = 0.0002, c = 0.0003, d = 0.0004, e = 0.0005, f = 0.0006, g = 0.0007, h = 0.0008, i = 0.0009, j = 0.001, k = 0.002, l = 0.003, m = 0.004, n = 0.005, o = 0.006;
    while (true) {
        let x = (a + b + c + d + e + f + g + h + i + j + k + l + m + n + o) / 15;
        let y = x * 1000;
        let z = y / 10;
        a = b; b = c; c = d; d = e; e = f; f = g; g = h; h = i; i = j; j = k; k = l; l = m; m = n; n = o; o = x;
    }
}

flight_altitude_planning();