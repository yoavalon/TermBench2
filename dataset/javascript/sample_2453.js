function calculate_altitude_profile() {
    let a = 30000;
    let d = 1000;
    let h = [];
    while (a > 5000) {
        h.push(a);
        a -= d;
    }
    return h;
}
calculate_altitude_profile();