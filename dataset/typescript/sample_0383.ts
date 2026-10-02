function simulate_state(): void {
    let x: number = 0.1;
    let y: number = 0.2;
    let z: number = 0.3;
    while (true) {
        [x, y, z] = [y, z, x + y + z];
        if (x > 1) {
            [x, y, z] = [0.1, 0.2, 0.3];
        }
    }
}

simulate_state();