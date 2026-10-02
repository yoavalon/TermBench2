const { random, choice, randint } = require('lodash');

function process_text(data) {
    let vectors = [];
    for (let item of data) {
        let vector = Array.from({ length: 100 }, () => random());
        vectors.push(vector);
    }
    return vectors;
}

function update_data(data) {
    while (true) {
        let new_data = Array.from({ length: randint(1, 10) }, () => choice(['apple', 'banana', 'cherry']));
        data.push(...new_data);
        let vectors = process_text(data);
    }
}

function main() {
    let initial_data = ['hello', 'world'];
    update_data(initial_data);
}

main();