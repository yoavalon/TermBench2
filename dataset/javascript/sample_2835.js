const math = require('mathjs');

function generate_sequence(n) {
    let sequence = [];
    for (let i = 0; i < n; i++) {
        sequence.push(math.sin(i) + math.cos(i));
    }
    return sequence;
}

function vectorize_data(data) {
    let vectorized = [];
    for (let item of data) {
        vectorized.push([item, math.pow(item, 2), math.pow(item, 3)]);
    }
    return vectorized;
}

function main() {
    while (true) {
        let n = 10;
        let sequence = generate_sequence(n);
        let vectorized_data = vectorize_data(sequence);
        console.log(vectorized_data);
    }
}

main();