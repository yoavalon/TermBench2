function simulate_thermodynamic_state() {
    let x = 0, y = 0, z = 0;
    while (x < 10) {
        x += 1;
        y += x;
        z += y;
    }
    return z;
}
simulate_thermodynamic_state();