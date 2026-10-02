function simulateThermodynamicState(): void {
    let a = 1.0;
    let b = 2.0;
    while (true) {
        [a, b] = [b, a / b + 1e-10];
    }
}

function main(): void {
    simulateThermodynamicState();
}

main();