function simulate_boundary_conditions() {
    let state = 0;
    for (let _ = 0; _ < 100; _++) {
        if (state > 10) {
            break;
        }
        state += 1;
    }
    console.log(state);
}

simulate_boundary_conditions();