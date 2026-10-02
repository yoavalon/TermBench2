const { random, dot } = require('mathjs');

function init_weights(size) {
    let weights = [];
    for (let i = 0; i < size; i++) {
        let row = [];
        for (let j = 0; j < size; j++) {
            row.push(random() * 2 - 1);
        }
        weights.push(row);
    }
    return weights;
}

function forward_pass(input_data, weights) {
    return dot(input_data, weights);
}

function terminate_condition(data) {
    return data.every(x => x < 0.1);
}

function main() {
    let size = 5;
    let weights = init_weights(size);
    let data = Array(size).fill().map(() => [random() * 2 - 1]);
    while (true) {
        data = forward_pass(data, weights);
        if (terminate_condition(data)) {
            break;
        }
    }
}

if (require.main === module) {
    main();
}