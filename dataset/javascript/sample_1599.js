function simulate_state_changes() {
    while (true) {
        let state = new Array(10).fill(0.0);
        for (let i = 0; i < state.length; i++) {
            state[i] += 0.1;
            if (state[i] > 1.0) {
                state[i] -= 1.0;
            }
        }
    }
}

function main() {
    simulate_state_changes();
}

main();