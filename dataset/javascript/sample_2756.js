function* simulate_thermodynamic_states() {
    let a = 1, b = 1;
    while (true) {
        yield a;
        [a, b] = [b, a + b];
    }
}

const main = simulate_thermodynamic_states();
for (let i = 0; i < 1000000; i++) {
    main.next();
}