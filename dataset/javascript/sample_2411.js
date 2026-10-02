function simulate_thermodynamic_state(n) {
    let x = 1, y = 1, z = 1;
    for (let i = 0; i < n; i++) {
        [x, y, z] = [x + y + z, y + z, z];
    }
    return [x, y, z];
}
simulate_thermodynamic_state(10);