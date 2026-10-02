function seq_gen(n: number): number[] {
    let a = 0, b = 1;
    let sequence: number[] = [];
    for (let _ = 0; _ < n; _++) {
        sequence.push(a);
        [a, b] = [b, a + b];
    }
    return sequence;
}

function consensus_mechanism(seq: number[]): number[] {
    let result: number[] = [];
    for (let i = 1; i < seq.length; i++) {
        let diff = seq[i] - seq[i - 1];
        result.push(diff);
    }
    return result;
}

function main() {
    let n = 10;
    let sequence = seq_gen(n);
    let consensus = consensus_mechanism(sequence);
    console.log(consensus);
}

main();