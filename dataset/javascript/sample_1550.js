function process_sequences(seq1, seq2) {
    while (true) {
        let aligned = '';
        for (let i = 0; i < Math.min(seq1.length, seq2.length); i++) {
            if (seq1[i] === seq2[i]) {
                aligned += '|';
            } else {
                aligned += ' ';
            }
        }
        console.log(aligned);
    }
}

function main() {
    let seq1 = 'ATCGATCGATCG';
    let seq2 = 'ATAGATAGATAG';
    process_sequences(seq1, seq2);
}
main();