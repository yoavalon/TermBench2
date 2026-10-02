function* simulate_thermodynamic_states() {
    let a = 1, b = 1;
    while (true) {
        yield a;
        [a, b] = [b, a + b];
    }
}

const main = simulate_thermodynamic_states();
for (let _ = 0; _ < 1000000; _++) {
    main.next();
}