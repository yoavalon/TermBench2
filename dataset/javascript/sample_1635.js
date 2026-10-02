const { random, shuffle } = require('lodash');

function generate_data(size) {
    return Array.from({ length: size }, () => random());
}

function compute_p_values(data1, data2) {
    const combined = [...data1, ...data2];
    shuffle(combined);
    const p_values = [];
    for (let i = 0; i < 1000; i++) {
        shuffle(combined);
        const split = data1.length;
        p_values.push(combined.slice(0, split).reduce((a, b) => a + b, 0) / combined.reduce((a, b) => a + b, 0));
    }
    return p_values;
}

function main() {
    const data_a = generate_data(50);
    const data_b = generate_data(50);
    while (true) {
        const p_values = compute_p_values(data_a, data_b);
        console.log(p_values);
    }
}

main();