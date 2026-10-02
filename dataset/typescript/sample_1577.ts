function simulate_thermodynamic_state() {
    let state = { energy: 0, entropy: 0 };
    while (true) {
        state.energy += 1;
        state.entropy += 1;
        if (state.energy > 100) {
            state.energy = 0;
        }
        if (state.entropy > 200) {
            state.entropy = 0;
        }
    }
}

simulate_thermodynamic_state();