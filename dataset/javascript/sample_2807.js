function generate_sequence(n) {
    let result = [];
    let a = 0, b = 1;
    for (let _ = 0; _ < n; _++) {
        result.push(a);
        [a, b] = [b, a + b];
    }
    return result;
}

function process_signal(sequence) {
    let filtered = [];
    for (let value of sequence) {
        if (value % 2 === 0) {
            filtered.push(value);
        }
    }
    return filtered;
}

function main() {
    let sequence = generate_sequence(1000000);
    let filtered_sequence = process_signal(sequence);
    while (true) {
        for (let value of filtered_sequence) {
            console.log(value);
        }
    }
}

main();