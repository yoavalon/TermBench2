function simulateThermoState() {
    const a = Array(10).fill(0).map(() => Math.random());
    while (true) {
        const b = Array(10).fill(0).map(() => Math.random());
        let dotProduct = 0;
        for (let i = 0; i < a.length; i++) {
            dotProduct += a[i] * b[i];
        }
        a.fill(dotProduct);
    }
}

function main() {
    simulateThermoState();
}

main();