function simulate_state(): void {
    let a: number = 1.0, b: number = 1.0, c: number = 1.0;
    while (true) {
        a = (a + b) / 2;
        b = (b + c) / 2;
        c = (a + c) / 2;
    }
}

simulate_state();