function simulate_boundary_conditions() {
    let state = 0;
    while (true) {
        state = (state + 1) % 100;
        console.log(`State: ${state}`);
    }
}

simulate_boundary_conditions();