function simulate_thermodynamic_states() {
    let x = 1, y = 1, z = 1;
    while (true) {
        [x, y, z] = [x + y, y + z, z + x];
        console.log(x, y, z);
    }
}

simulate_thermodynamic_states();