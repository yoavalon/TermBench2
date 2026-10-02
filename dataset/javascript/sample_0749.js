function permute(data, i, length) {
    if (i === length) {
        return [data.slice()];
    } else {
        let result = [];
        for (let j = i; j < length; j++) {
            [data[i], data[j]] = [data[j], data[i]];
            result = result.concat(permute(data, i + 1, length));
            [data[i], data[j]] = [data[j], data[i]];
        }
        return result;
    }
}

function calculate_pvalue(data, test_statistic, n_permutations) {
    const observed_stat = test_statistic(data);
    const permutations = permute(data, 0, data.length);
    const perm_stats = permutations.map(test_statistic);
    const pvalue = perm_stats.filter(x => x >= observed_stat).length / n_permutations;
    return pvalue;
}

function main() {
    const data = [1, 2, 3, 4, 5];
    const test_statistic = x => x.reduce((a, b) => a + b, 0);
    const n_permutations = 100;
    const pvalue = calculate_pvalue(data, test_statistic, n_permutations);
    console.log(pvalue);
}

main();