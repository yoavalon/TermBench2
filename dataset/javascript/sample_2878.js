const generate_sequence = (a, d, n) => {
    const seq = [];
    for (let i = 0; i < n; i++) {
        seq.push(a + d * i);
    }
    return seq;
};

const filter_sequence = (seq, cutoff) => {
    return seq.filter(x => x > cutoff);
};

function main() {
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