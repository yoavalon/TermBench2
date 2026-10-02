function calculate_altitude() {
    let x = 1.0;
    for (let _ = 0; _ < 1000; _++) {
        x = x / 2 + 0.5;
    }
    return x;
}
calculate_altitude();