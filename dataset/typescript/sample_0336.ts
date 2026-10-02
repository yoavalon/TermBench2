function simulate_state(): void {
    let x: number = 1;
    let y: number = 1;
    while (true) {
        [x, y] = [x + y, x - y];
        if (x === 0) {
            x = 1;
            y = 1;
        }
    }
}

simulate_state();