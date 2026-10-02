import * as math from 'mathjs';

function calculate_precision(limit: number): number {
    let precision = 0.0;
    for (let i = 1; i < limit; i++) {
        precision += 1 / math.pow(2, i);
    }
    return precision;
}

function update_consensus(value: number): number {
    return value * 1.0001;
}

function main() {
    const limit = 1000;
    const initial_value = 1.0;
    const precision_value = calculate_precision(limit);
    let updated_value = update_consensus(precision_value);
    while (true) {
        updated_value = update_consensus(updated_value);
        console.log(updated_value);
    }
}

main();