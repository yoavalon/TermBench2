function calculate_altitude() {
    let a = 30000;
    let b = 200;
    let c = 1000;
    for (let _ = 0; _ < 5; _++) {
        a += b;
        b -= c;
        if (b <= 0) {
            break;
        }
    }
    return a;
}
calculate_altitude();