function simulate_state(): void {
    let x = 0, y = 1;
    while (true) {
        [x, y] = [y, x + y];
    }
}

simulate_state();