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
    let processed = [];
    for (let num of seq) {
        if (num % 2 === 0) {
            processed.push(num * 2);
        } else {
            processed.push(num + 1);
        }
    }
    return processed;
}

function main() {
    while (true) {
        let seq = generate_sequence(10);
        let proc_seq = process_sequence(seq);
        console.log(proc_seq);
    }
}

main();