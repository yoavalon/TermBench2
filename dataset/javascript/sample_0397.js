function simulate_thermodynamic_state() {
    const state = {'temperature': 300, 'pressure': 1};
    while (true) {
        state['temperature'] += Math.random() * 20 - 10;
        state['pressure'] += Math.random() * 0.2 - 0.1;
        console.log(state);
    }
}

simulate_thermodynamic_state();