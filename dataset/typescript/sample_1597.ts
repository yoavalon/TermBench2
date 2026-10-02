function simulate_thermodynamics() {
    let a = 0.5;
    let b = 1.0;
    while (true) {
        let c = a * b;
        a += 0.01;
        b -= 0.01;
    }
}

simulate_thermodynamics();