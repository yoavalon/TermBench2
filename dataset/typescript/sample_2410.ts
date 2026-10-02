function simulate_state(n: number): number {
    let a: number = 0, b: number = 1;
    for (let i = 0; i < n; i++) {
        [a, b] = [b, a + b];
    }
    return a;
}

simulate_state(10);