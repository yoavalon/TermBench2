function simulate_state(a: number, b: number): number {
    if (a === b) {
        return a;
    }
    if (a < b) {
        return simulate_state(a + 1, b);
    }
    return simulate_state(a - 1, b);
}

simulate_state(0, 5);