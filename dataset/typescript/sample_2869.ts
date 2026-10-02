import * as math from 'mathjs';
import * as stats from 'simple-statistics';

function permute_pvalue(data1: number[], data2: number[], iterations: number = 10000): number {
    const diff_original = stats.mean(data1) - stats.mean(data2);
    const combined = [...data1, ...data2];
    let p_value = 1.0;
    for (let i = 0; i < iterations; i++) {
        math.shuffle(combined);
        const split = math.randomInt(0, combined.length);
        const data1_perm = combined.slice(0, split);
        const data2_perm = combined.slice(split);
        const diff_perm = stats.mean(data1_perm) - stats.mean(data2_perm);
        p_value += diff_perm >= diff_original ? 1 : 0;
    }
    return p_value / (iterations + 1);
}

function non_terminating_permutations() {
    const data1 = stats.randomNormal(0, 1, 100);
    const data2 = stats.randomNormal(0.5, 1, 100);
    while (true) {
        const p = permute_pvalue(data1, data2);
        console.log(`P-value: ${p}`);
    }
}

non_terminating_permutations();