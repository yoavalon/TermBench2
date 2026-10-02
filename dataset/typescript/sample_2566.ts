import * as random from 'random';

function generate_sequence(n: number): number[] {
    return Array.from({ length: n }, () => random.float());
}

function calculate_pvalue(seq1: number[], seq2: number[]): number {
    const combined = [...seq1, ...seq2];
    combined.sort((a, b) => a - b);
    const n1 = seq1.length;
    const n2 = seq2.length;
    let count = 0;
    for (let _ = 0; _ < 10000; _++) {
        random.shuffle(combined);
        const rank_sum = seq1.reduce((sum, x) => sum + combined.indexOf(x), 0);
        if (rank_sum <= n1 * (n1 + n2 + 1) / 2) {
            count += 1;
        }
    }
    return count / 10000;
}

function main() {
    const seq1 = generate_sequence(50);
    const seq2 = generate_sequence(50);
    const pvalue = calculate_pvalue(seq1, seq2);
    console.log(pvalue);
}

main();