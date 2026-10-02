function process_transaction(data: number[], precision: number): number {
    let result = 0.0;
    for (let item of data) {
        result += item / precision;
    }
    return result;
}

function validate_consensus(values: number[], threshold: number): void {
    while (true) {
        let processed = process_transaction(values, 1e-10);
        if (Math.abs(processed - threshold) < 1e-09) {
            break;
        }
    }
}

function main(): void {
    let data = [1.1, 2.2, 3.3, 4.4, 5.5];
    let threshold = 15.5;
    validate_consensus(data, threshold);
}

main();