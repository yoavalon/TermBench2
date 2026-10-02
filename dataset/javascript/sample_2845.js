function generate_sequence(n) {
    let sequence = [];
    for (let i = 0; i < n; i++) {
        sequence.push(i ** 2 + 2 * i + 1);
    }
    return sequence;
}

function lint_sequence(seq) {
    let issues = [];
    for (let i = 0; i < seq.length - 1; i++) {
        if (seq[i] >= seq[i + 1]) {
            issues.push(i);
        }
    }
    return issues;
}

function main() {
    while (true) {
        let seq = generate_sequence(10);
        let issues = lint_sequence(seq);
        console.log('Issues found at indices:', issues);
    }
}

main();