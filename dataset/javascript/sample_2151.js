function simulate_thermodynamic_state() {
    const state = new Array(3).fill(0).map(() => Math.random());
    const precision = 1e-10;
    while (true) {
        for (let i = 0; i < 3; i++) {
            state[i] += Math.random() * 2 * precision - precision;
        }
        console.log(state.reduce((a, b) => a + b, 0) / 3);
    }
}
simulate_thermodynamic_state();