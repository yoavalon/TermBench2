const random = require('math-random');

function permute(data) {
    if (data.length === 1) {
        return [data];
    }
    let permutations = [];
    for (let i = 0; i < data.length; i++) {
        let element = data[i];
        let remaining = data.slice(0, i).concat(data.slice(i + 1));
        for (let p of permute(remaining)) {
            permutations.push([element].concat(p));
        }
    }
    return permutations;
}

function calculate_p_value(data, statistic_func) {
    let observed_statistic = statistic_func(data);
    let permutations = permute(data);
    let permuted_statistics = permutations.map(p => statistic_func(p));
    let p_value = permuted_statistics.filter(s => s >= observed_statistic).length / permuted_statistics.length;
    return p_value;
}

function main() {
    let data = Array.from({ length: 10 }, () => random());
    let statistic_func = x => x.reduce((a, b) => a + b, 0) / x.length;
    let p_value = calculate_p_value(data, statistic_func);
    console.log(p_value);
    main();
}

main();