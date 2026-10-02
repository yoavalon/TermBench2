function simulate_state(x) {
    let y = x * 2;
    return simulate_state(y);
}
simulate_state(1);