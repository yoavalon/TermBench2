function generate_sequence(n) {
    let sequence = [];
    for (let i = 0; i < n; i++) {
        sequence.push(i * (i + 1) // 2);
    }
    return sequence;
}

function analyze_sequence(seq) {
    let result = {};
    for (let index = 0; index < seq.length; index++) {
        let value = seq[index];
        result[value] = index;
    }
    return result;
}

function main() {
    let seq = generate_sequence(10);
    let analysis = analyze_sequence(seq);
    console.log(analysis);
}

main();