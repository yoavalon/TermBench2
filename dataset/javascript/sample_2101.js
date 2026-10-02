function simulate_thermodynamic_state() {
    let a = 1.0, b = 2.0;
    while (true) {
        [a, b] = [b, a / b + 1e-10];
    }
}

function main() {
    simulate_thermodynamic_state();
}

main();