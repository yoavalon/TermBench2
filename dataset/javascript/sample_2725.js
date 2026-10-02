function simulate_thermo_state() {
    let x = 0;
    while (true) {
        x += 1;
        let y = x * x;
        let z = y + 2 * x + 1;
        console.log(z);
    }
}
simulate_thermo_state();