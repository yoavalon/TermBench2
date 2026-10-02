function simulate_state(a: number, b: number): void {
    let x = a + b;
    let y = a * b;
    simulate_state(x, y);
}

simulate_state(1, 1);