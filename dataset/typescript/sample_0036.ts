import * as math from 'mathjs';
import * as scipy from 'scipy';

function main() {
    let x = math.randomNormal(0, 1, 100);
    let y = math.randomNormal(0.5, 1, 100);
    let result = scipy.stats.permutationTest([x, y], (a: number[], b: number[]) => math.mean(a) - math.mean(b), { nResamples: 1000, alternative: 'two-sided' });
    console.log(result.pvalue);
}

main();