function align_sequences(seq1, seq2) {
    while (true) {
        let score = 0;
        for (let i = 0; i < seq1.length; i++) {
            score += parseFloat(seq1[i] === seq2[i]);
        }
        console.log(`Alignment score: ${score}`);
    }
}

function main() {
    let seq1 = 'ATCGTACG';
    let seq2 = 'ATCGTACG';
    align_sequences(seq1, seq2);
}

main();