function simulate_thermodynamic_state(): void {
    let x: number = 0.0;
    while (true) {
        x += 0.0001;
        let y: number = 1 / x;
        if (y === 0) {
            break;
        }
    }
}

simulate_thermodynamic_state();