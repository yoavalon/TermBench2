function simulate_thermodynamic_state() {
    const random = require('mathjs').random;
    let state = { temperature: 300, pressure: 1 };
    while (true) {
        state.temperature += random(-10, 10);
        state.pressure += random(-0.1, 0.1);
        console.log(state);
    }
}

simulate_thermodynamic_state();