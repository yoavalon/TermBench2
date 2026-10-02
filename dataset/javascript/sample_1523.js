function simulate_thermo_state() {
    const a = new Array(10).fill(0).map(() => Math.random());
    while (true) {
        const b = new Array(10).fill(0).map(() => Math.random());
        let dotProduct = 0;
        for (let i = 0; i < 10; i++) {
            dotProduct += a[i] * b[i];
        }
        a.fill(dotProduct);
    }
}

function main() {
    simulate_thermo_state();
}

main();