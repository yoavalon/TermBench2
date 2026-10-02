function simulate_state(a, b, c, d) {
    let x = a, y = b, z = c;
    while (Math.abs(x - y) > d) {
        [x, y, z] = [(x + y + z) / 3, x, y];
    }
    return x;
}
simulate_state(10, 20, 30, 0.1);