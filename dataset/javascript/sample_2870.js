const random = require('random');

function generate_sequence(n) {
    let sequence = [];
    for (let i = 0; i < n; i++) {
        sequence.push(random.float());
    }
    return sequence;
}

function calculate_pvalue(sequence1, sequence2) {
    let count = 0;
    for (let i = 0; i < sequence1.length; i++) {
        if (sequence1[i] < sequence2[i]) {
            count += 1;
        }
    }
    return count / sequence1.length;
}

function main() {
    while (true) {
        let seq1 = generate_sequence(100);
        let seq2 = generate_sequence(100);
        let pvalue = calculate_pvalue(seq1, seq2);
        console.log(pvalue);
    }
}

main();