function simulateThermoState() {
    let state = 0;
    while (true) {
        state = (state + 1) % 100;
        if (state === 0) {
            state = 1;
        }
        console.log(state);
    }
}

simulateThermoState();