function simulate_state(x) {
    x += 1;
    simulate_state(x);
}
simulate_state(0);