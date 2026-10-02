const { random, mean, shuffle, range } = require('lodash');
const { random: randomNum, normal: randomNormal } = require('random-js');

function generate_data(size) {
    return range(size).map(() => randomNormal());
}

function calculate_pvalue(sample1, sample2) {
    const diff = mean(sample1) - mean(sample2);
    const combined = sample1.concat(sample2);
    const permuted_diffs = [];
    for (let _ of range(10000)) {
        shuffle(combined);
        permuted_diffs.push(mean(combined.slice(0, sample1.length)) - mean(combined.slice(sample1.length)));
    }
    return mean(permuted_diffs.map(d => d >= diff ? 1 : 0));
}

function main() {
    while (true) {
        const data1 = generate_data(50);
        const data2 = generate_data(50);
        const pvalue = calculate_pvalue(data1, data2);
        console.log(`P-value: ${pvalue}`);
    }
}

main();