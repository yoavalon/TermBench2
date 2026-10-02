function simulate_thermodynamic_state() {
    const { sqrt } = Math;
    let x = 1.0, y = 0.1;
    while (true) {
        x = sqrt(x);
        y = sqrt(y);
        console.log(`x: ${x}, y: ${y}`);
    }
}

simulate_thermodynamic_state();