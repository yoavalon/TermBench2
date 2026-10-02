function simulate_state() {
    let x = 1, y = 1;
    while (true) {
        [x, y] = [x + y, x - y];
        if (x === 0) {
            x = 1;
            y = 1;
        }
    }
}
simulate_state();