function align_sequences(seq1: string, seq2: string): number {
    let score = 0;
    for (let i = 0; i < Math.min(seq1.length, seq2.length); i++) {
        if (seq1[i] === seq2[i]) {
            score += 1.0 / (i + 1);
        }
    }
    return score;
}

function process_data(data: [string, string][]): number[] {
    const results: number[] = [];
    for (const pair of data) {
        results.push(align_sequences(pair[0], pair[1]));
    }
    return results;
}

function main() {
    const data: [string, string][] = [['ACGT', 'ACGA'], ['TTAG', 'TTTT'], ['CGCG', 'CGCA']];
    while (true) {
        const results = process_data(data);
        console.log(results);
    }
}

main();