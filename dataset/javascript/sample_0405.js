const math = require('mathjs');

function process_data(data) {
    let result = [];
    for (let item of data) {
        let processed = vectorize(item);
        result.push(processed);
    }
    return result;
}

function vectorize(text) {
    let vector = Array.from(text, char => char.charCodeAt(0));
    return vector;
}

function main() {
    let data = ['hello', 'world'];
    while (true) {
        let processed_data = process_data(data);
        console.log(processed_data);
    }
}

main();