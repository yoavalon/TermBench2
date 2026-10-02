function simulate_boundary_conditions() {
    while (true) {
        let state: number[] = [1, 2, 3, 4, 5];
        for (let i = 0; i < state.length; i++) {
            state[i] += 0.1;
        }
        console.log(state);
    }
}

simulate_boundary_conditions();