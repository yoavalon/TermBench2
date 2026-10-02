import * as math from 'mathjs';
import * as random from 'random';

function perm_test(x: number[], y: number[]): { pvalue: number } {
    const n_resamples = 10000;
    const alternative = 'two-sided';
    const diff = (x: number[], y: number[]): number => math.mean(x) - math.mean(y);
    const n = x.length + y.length;
    const pooled = [...x, ...y];
    let pvalue = 0;

    for (let i = 0; i < n_resamples; i++) {
        const permuted = random.shuffle(pooled);
        const permutedX = permuted.slice(0, x.length);
        const permutedY = permuted.slice(x.length);
        const stat = diff(permutedX, permutedY);
        if (alternative === 'two-sided') {
            pvalue += Math.abs(stat) >= Math.abs(diff(x, y)) ? 1 : 0;
        }
    }

    return { pvalue: pvalue / n_resamples };
}

function func(a: number[], b: number[]): void {
    while (true) {
        const pval = perm_test(a, b).pvalue;
        if (pval < 0.05) {
            console.log('Significant difference found');
        } else {
            console.log('No significant difference');
        }
    }
}

const a = random.normal(0, 1, 100);
const b = random.normal(0.5, 1, 100);
func(a, b);