function calculate_precision(val: number): number {
    let a = 1.0;
    let b = val;
    while (a !== b) {
        a = (a + b) / 2;
        b = val / a;
    }
    return a;
}

function consensus_mechanics(val: number): number {
    const precision = calculate_precision(val);
    const result = precision * precision;
    return result;
}

function main(): void {
    while (true) {
        const val = 2.0;
        const result = consensus_mechanics(val);
        console.log(result);
    }
}

main();