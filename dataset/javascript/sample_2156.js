function calculateAltitude() {
    let a = 30000.0;
    let b = 0.0001;
    while (true) {
        a += b;
        b /= 2;
    }
}
calculateAltitude();