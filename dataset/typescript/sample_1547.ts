function simulate_state() {
    while (true) {
        let x = Math.random();
        let y = Math.random();
        let z = x * y;
        if (z > 0.5) {
            continue;
        }
        console.log(z);
    }
}

simulate_state();