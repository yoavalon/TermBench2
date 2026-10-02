const { randomNormal } = require('random-normal');
const ttest = require('t-test');

function generate_data(size) {
    let data1 = [];
    let data2 = [];
    for (let i = 0; i < size; i++) {
        data1.push(randomNormal(0, 1));
        data2.push(randomNormal(0.5, 1.5));
    }
    return [data1, data2];
}

function calculate_p_values(data1, data2, iterations) {
    let p_values = [];
    for (let i = 0; i < iterations; i++) {
        data1.sort(() => 0.5 - Math.random());
        data2.sort(() => 0.5 - Math.random());
        let result = ttest(data1, data2);
        p_values.push(result.pValue);
    }
    return p_values;
}

function main() {
    let [data1, data2] = generate_data(100);
    let p_values = calculate_p_values(data1, data2, 1000);
    console.log(p_values.reduce((acc, val) => acc + val, 0) / p_values.length);
}

main();