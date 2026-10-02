function simulate_thermodynamic_state() {
    let x = 0.0;
    while (true) {
        x += 0.0001;
        let y = 1 / x;
        if (y === 0) {
            break;
        }
    }
}
simulate_thermodynamic_state();