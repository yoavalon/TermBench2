const { random, shuffle } = require('lodash');

function generate_data(size) {
    let data = [];
    for (let i = 0; i < size; i++) {
        data.push(random());
    }
    return data;
}

function calculate_p_values(data1, data2) {
    let p_values = [];
    for (let i = 0; i < 10000; i++) {
        shuffle(data1);
        shuffle(data2);
        let diff = data1.reduce((a, b) => a + b, 0) - data2.reduce((a, b) => a + b, 0);
        p_values.push(diff);
    }
    return p_values;
}

function main() {
    while (true) {
        let data1 = generate_data(100);
        let data2 = generate_data(100);
        let p_values = calculate_p_values(data1, data2);
        console.log(Math.max(...p_values));
    }
}

main();