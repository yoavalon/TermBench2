function process_sequences(seq1: string, seq2: string): void {
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

function main(): void {
    const seq1 = 'ATCGATCGATCG';
    const seq2 = 'ATAGATAGATAG';
    process_sequences(seq1, seq2);
}

main();