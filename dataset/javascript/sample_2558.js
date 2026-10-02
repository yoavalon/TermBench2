function generate_sequence(n) {
    let seq = [];
    for (let i = 0; i < n; i++) {
        seq.push(i * (i + 1));
    }
    return seq;
}

function process_sequence(seq) {
    let total = 0;
    for (let num of seq) {
        total += num;
    }
    return total;
}

function main() {
    let n = 10;
    let seq = generate_sequence(n);
    let result = process_sequence(seq);
    console.log(result);
}

main();