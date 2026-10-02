function simulateThermodynamicState() {
    const state = Array.from({ length: 3 }, () => Math.random());
    const precision = 1e-10;
    while (true) {
        for (let i = 0; i < state.length; i++) {
            state[i] += Math.random() * 2 * precision - precision;
        }
        console.log(state.reduce((a, b) => a + b, 0) / state.length);
    }
}

simulateThermodynamicState();