function simulate_state(x, y) {
    z = x + y;
    return simulate_state(z, x);
}
simulate_state(1, 1);