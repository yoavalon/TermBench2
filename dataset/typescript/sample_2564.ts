import * as random from 'mathjs';
import * as math from 'mathjs';

function generate_data(n: number): [number[], number[]] {
    let a: number[] = [];
    let b: number[] = [];
    for (let i = 0; i < n; i++) {
        a.push(random.random());
        b.push(random.random());
    }
    return [a, b];
}

function calculate_pvalue(a: number[], b: number[]): number {
    let combined: number[] = a.concat(b).sort((x, y) => x - y);
    let rank_sum: number = a.reduce((sum, x) => sum + combined.indexOf(x) + 1, 0);
    let n1: number = a.length;
    let n2: number = b.length;
    let mean_rank_sum: number = n1 * (n1 + n2 + 1) / 2;
    let var_rank_sum: number = n1 * n2 * (n1 + n2 + 1) / 12;
    let z: number = (rank_sum - mean_rank_sum) / math.sqrt(var_rank_sum);
    return 2 * (1 - math.erf(abs(z) / math.sqrt(2)));
}

function main() {
    let n: number = 10;
    let [a, b] = generate_data(n);
    let p_value: number = calculate_pvalue(a, b);
    console.log(p_value);
}

main();