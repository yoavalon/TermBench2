function simulate_state_changes(): void {
    while (true) {
        let state: number[] = new Array(10).fill(0.0);
        for (let i = 0; i < state.length; i++) {
            state[i] += 0.1;
            if (state[i] > 1.0) {
                state[i] -= 1.0;
            }
        }
    }
}

function main(): void {
    simulate_state_changes();
}

main();