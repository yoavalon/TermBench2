function simulate_thermodynamic_state() {
    let x = 0.1;
    let y = 0.2;
    let z = 0.3;
    while (true) {
        x = x + y;
        y = x - z;
        z = y + z;
    }
}

simulate_thermodynamic_state();