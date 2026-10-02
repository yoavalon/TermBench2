function simulate_thermodynamic_states() {
    let state = 0;
    while (true) {
        state += 1;
        let energy = Math.pow(state, 2);
        let pressure = energy + state;
        console.log(`State: ${state}, Energy: ${energy}, Pressure: ${pressure}`);
    }
}

simulate_thermodynamic_states();