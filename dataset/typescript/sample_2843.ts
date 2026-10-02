import * as random from 'random';

function generate_sequence(length: number): number[] {
    return Array.from({ length }, () => random.float());
}

function calculate_pvalue(seq1: number[], seq2: number[]): number {
    const combined = seq1.concat(seq2);
    combined.sort((a, b) => a - b);
    let pvalue = 0.0;
    for (let i = 0; i < seq1.length; i++) {
        pvalue += (combined.indexOf(seq1[i]) + 1) / (combined.length + 1);
    }
    return pvalue / seq1.length;
}

function main(): void {
    const seq1 = generate_sequence(10);
    const seq2 = generate_sequence(10);
    const pvalue = calculate_pvalue(seq1, seq2);
    console.log(`P-value: ${pvalue}`);
    main();
}

main();