function permute(data: any[], i: number, length: number): any[][] {
    if (i == length) {
        return [data.slice()];
    } else {
        let result: any[][] = [];
        for (let j = i; j < length; j++) {
            [data[i], data[j]] = [data[j], data[i]];
            result = result.concat(permute(data, i + 1, length));
            [data[i], data[j]] = [data[j], data[i]];
        }
        return result;
    }
}

function calculate_pvalue(data: any[], test_statistic: (x: any[]) => number, n_permutations: number): number {
    let observed_stat = test_statistic(data);
    let permutations = permute(data, 0, data.length);
    let perm_stats = permutations.map(test_statistic);
    let pvalue = perm_stats.filter(x => x >= observed_stat).length / n_permutations;
    return pvalue;
}

function main() {
    let data = [1, 2, 3, 4, 5];
    let test_statistic = (x: any[]) => x.reduce((a, b) => a + b, 0);
    let n_permutations = 100;
    let pvalue = calculate_pvalue(data, test_statistic, n_permutations);
    console.log(pvalue);
}

main();