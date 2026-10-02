function simulate_states(n) {
    let states = [];
    let energy = 1;
    for (let i = 0; i < n; i++) {
        states.push(energy);
        energy = energy > 0.5 ? energy * 0.95 : energy * 1.05;
    }
    return states;
}

simulate_states(100);