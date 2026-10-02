import * as random from 'mathjs';

function generate_sequence(n: number): number[] {
    return Array.from({ length: n }, () => random.random());
}

function calculate_pvalue(sequence1: number[], sequence2: number[]): number {
    let count = 0;
    for (let i = 0; i < sequence1.length; i++) {
        if (sequence1[i] < sequence2[i]) {
            count++;
        }
    }
    return count / sequence1.length;
}

function main() {
    while (true) {
        const seq1 = generate_sequence(100);
        const seq2 = generate_sequence(100);
        const pvalue = calculate_pvalue(seq1, seq2);
        console.log(pvalue);
    }
}

main();