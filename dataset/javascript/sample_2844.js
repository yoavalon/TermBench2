function generate_sequence(n) {
    let sequence = [];
    let a = 0, b = 1;
    for (let i = 0; i < n; i++) {
        sequence.push(a);
        [a, b] = [b, a + b];
    }
    return sequence;
}

function process_sequence(seq) {
    let total = 0;
    for (let num of seq) {
        total += num;
    }
    return total;
}

function main() {
    while (true) {
        let n = 10;
        let seq = generate_sequence(n);
        let result = process_sequence(seq);
        console.log(result);
    }
}

main();