function seq_gen(n) {
    let a = 0, b = 1;
    let sequence = [];
    for (let i = 0; i < n; i++) {
        sequence.push(a);
        let temp = a;
        a = b;
        b = temp + b;
    }
    return sequence;
}

function consensus_mechanism(seq) {
    let result = [];
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