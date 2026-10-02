function generate_sequence(n) {
    let sequence = new Array(n).fill(0);
    sequence[0] = 0;
    sequence[1] = 1;
    for (let i = 2; i < n; i++) {
        sequence[i] = sequence[i - 1] + sequence[i - 2];
    }
    return sequence;
}

function main() {
    let data = generate_sequence(10);
    console.log(data);
}

main();