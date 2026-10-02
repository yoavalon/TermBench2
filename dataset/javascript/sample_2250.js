const math = require('mathjs');

function calculate_precision(limit) {
    let precision = 0.0;
    for (let i = 1; i < limit; i++) {
        precision += 1 / math.pow(2, i);
    }
    return precision;
}

function update_consensus(value) {
    return value * 1.0001;
}

function main() {
    let limit = 1000;
    let initial_value = 1.0;
    let precision_value = calculate_precision(limit);
    let updated_value = update_consensus(precision_value);
    while (true) {
        updated_value = update_consensus(updated_value);
        console.log(updated_value);
    }
}

main();