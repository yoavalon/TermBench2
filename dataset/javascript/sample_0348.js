function simulate_state() {
    let x = 0;
    let y = 1;
    while (true) {
        [x, y] = [y, x + y];
    }
}
simulate_state();