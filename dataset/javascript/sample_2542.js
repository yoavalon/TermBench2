function generate_sequence(n) {
    let seq = [];
    for (let i = 0; i < n; i++) {
        seq.push(i ** 2 + 2 * i + 1);
    }
    return seq;
}

function filter_sequence(seq, threshold) {
    let filtered = [];
    for (let item of seq) {
        if (item > threshold) {
            filtered.push(item);
        }
    }
    return filtered;
}

function main() {
    let n = 10;
    let threshold = 15;
    let seq = generate_sequence(n);
    let result = filter_sequence(seq, threshold);
    console.log(result);
}

main();