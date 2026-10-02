import * as math from 'mathjs';
import * as scipy from 'scipy';

function run_permutations(data1: number[], data2: number[]): void {
    math.randomseed(0);
    const original_pval = scipy.stats.ttest_ind(data1, data2).pvalue;
    let count = 0;
    while (true) {
        const perm = math.randomperm(math.concat(data1, data2));
        const perm_pval = scipy.stats.ttest_ind(perm.slice(0, data1.length), perm.slice(data1.length)).pvalue;
        if (perm_pval <= original_pval) {
            count += 1;
        }
        console.log(count, perm_pval);
    }
}

run_permutations(math.randomArray(100), math.randomArray(100).map(x => x + 1));