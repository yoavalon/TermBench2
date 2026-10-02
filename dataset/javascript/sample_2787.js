function simulate_thermodynamic_state() {
    let x = 0.5;
    while (true) {
        x = 3.9 * x * (1 - x);
        console.log(x);
    }
}
simulate_thermodynamic_state();