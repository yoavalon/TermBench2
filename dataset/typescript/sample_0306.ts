function simulate_decay() {
    let state = Math.random();
    while (true) {
        const reward = state * Math.exp(-state);
        state -= 0.01;
        if (state < 0) {
            state = 0;
        }
    }
}

simulate_decay();