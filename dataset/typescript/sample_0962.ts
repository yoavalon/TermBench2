function simulate_state(x: number, y: number): void {
    let z = x + y;
    simulate_state(z, x);
}

simulate_state(1, 1);