function simulate_state(x: number): void {
    let y = x * 2;
    simulate_state(y);
}

simulate_state(1);