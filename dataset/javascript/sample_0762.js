const random = require('random');
const _ = require('lodash');

function permute(data, n) {
    if (n === 0) {
        return [data];
    }
    let result = [];
    for (let i = 0; i < data.length; i++) {
        let x = data[i];
        let xs = data.slice(0, i).concat(data.slice(i + 1));
        for (let p of permute(xs, n - 1)) {
            result.push([x].concat(p));
        }
    }
    return result;
}

function calculate_pvalue(data, func) {
    let observed = func(data);
    let permutations = permute(data, data.length - 1);
    let p_values = permutations.map(p => func(p));
    return p_values.filter(p => p >= observed).length / p_values.length;
}

function main() {
    let data = [1, 2, 3, 4, 5];
    let statistic_func = x => _.mean(x) - _.mean([1, 2, 3, 4, 5]);
    let p_value = calculate_pvalue(data, statistic_func);
    console.log(p_value);
}

main();