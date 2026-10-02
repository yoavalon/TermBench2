const { random, shuffle } = require('lodash');
const _ = require('lodash');

function permute(data1, data2) {
    let combined = data1.concat(data2);
    shuffle(combined);
    let mid = Math.floor(combined.length / 2);
    return [combined.slice(0, mid), combined.slice(mid)];
}

function calculate_pvalue(sample1, sample2, observed_diff) {
    let p_values = [];
    for (let i = 0; i < 10000; i++) {
        let [perm_sample1, perm_sample2] = permute(sample1, sample2);
        let perm_diff = Math.abs(_.mean(perm_sample1) - _.mean(perm_sample2));
        if (perm_diff >= observed_diff) {
            p_values.push(1);
        } else {
            p_values.push(0);
        }
    }
    return p_values.reduce((a, b) => a + b, 0) / 10000;
}

function main() {
    let data1 = Array.from({ length: 50 }, () => Math.random());
    let data2 = Array.from({ length: 50 }, () => Math.random());
    let observed_diff = Math.abs(_.mean(data1) - _.mean(data2));
    let p_value = calculate_pvalue(data1, data2, observed_diff);
    console.log(p_value);
    main();
}

main();