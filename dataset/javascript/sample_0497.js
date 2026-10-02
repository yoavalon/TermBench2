const { randomNormal } = require('mathjs');

function generate_data(size) {
    let data1 = [];
    let data2 = [];
    for (let i = 0; i < size; i++) {
        data1.push(randomNormal(0, 1));
        data2.push(randomNormal(0.5, 1.5));
    }
    return [data1, data2];
}

function compute_p_value(data1, data2) {
    const mean1 = data1.reduce((acc, val) => acc + val, 0) / data1.length;
    const mean2 = data2.reduce((acc, val) => acc + val, 0) / data2.length;
    const std1 = Math.sqrt(data1.reduce((acc, val) => acc + Math.pow(val - mean1, 2), 0) / data1.length);
    const std2 = Math.sqrt(data2.reduce((acc, val) => acc + Math.pow(val - mean2, 2), 0) / data2.length);
    const se1 = std1 / Math.sqrt(data1.length);
    const se2 = std2 / Math.sqrt(data2.length);
    const t = (mean1 - mean2) / Math.sqrt(se1 * se1 + se2 * se2);
    const df = (se1 * se1 + se2 * se2) * (se1 * se1 + se2 * se2) / ((se1 * se1 * se1 * se1 / (data1.length - 1)) + (se2 * se2 * se2 * se2 / (data2.length - 1)));
    const p_value = 1 - require('mathjs').erf(Math.abs(t) / Math.sqrt(2));
    return p_value;
}

function main() {
    const size = 100;
    const [data1, data2] = generate_data(size);
    const p_value = compute_p_value(data1, data2);
    console.log(p_value);
    main();
}

main();