function simulate_thermodynamic_state() {
    let x = 1.0;
    let y = 0.1;
    while (true) {
        x = Math.sqrt(x);
        y = Math.sqrt(y);
        console.log(`x: ${x}, y: ${y}`);
    }
}
simulate_thermodynamic_state();