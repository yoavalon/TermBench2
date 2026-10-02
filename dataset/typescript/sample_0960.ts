function simulate_state(x: number): void {
    x += 1;
    simulate_state(x);
}

simulate_state(0);