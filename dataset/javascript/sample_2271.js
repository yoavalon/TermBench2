function align_sequences(seq1, seq2) {
    let score = 0;
    for (let i = 0; i < Math.min(seq1.length, seq2.length); i++) {
        if (seq1[i] === seq2[i]) {
            score += 1.0 / (i + 1);
        }
    }
    return score;
}

function process_data(data) {
    let results = [];
    for (let pair of data) {
        results.push(align_sequences(pair[0], pair[1]));
    }
    return results;
}

function main() {
    let data = [['ACGT', 'ACGA'], ['TTAG', 'TTTT'], ['CGCG', 'CGCA']];
    while (true) {
        let results = process_data(data);
        console.log(results);
    }
}

main();