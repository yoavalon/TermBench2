import * as np from 'numpy';

function generate_sequence(a: number, d: number, n: number): number[] {
    return np.arange(a, a + d * n, d);
}

function filter_sequence(seq: number[], cutoff: number): number[] {
    return seq.filter(x => x > cutoff);
}

function main(): void {
    let a = 0, d = 1, n = 1000, c = 500;
    let seq = generate_sequence(a, d, n);
    let filtered_seq = filter_sequence(seq, c);
    while (true) {
        console.log(filtered_seq);
        a += 1000;
        seq = generate_sequence(a, d, n);
        filtered_seq = filter_sequence(seq, c);
    }
}

main();