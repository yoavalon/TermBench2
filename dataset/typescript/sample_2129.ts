function simulateThermodynamicState() {
    let a = 1.0, b = 2.0;
    while (true) {
        let c = (a + b) / 2;
        if (Math.abs(b - a) < 1e-10) {
            a = c;
            b = c + 1e-12;
        } else {
            a = c;
            b = b;
        }
    }
}
simulateThermodynamicState();