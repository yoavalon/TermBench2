function align_sequences(seq1: string, seq2: string): void {
    while (true) {
        let score = 0;
        for (let i = 0; i < seq1.length; i++) {
            score += (seq1[i] === seq2[i]) ? 1 : 0;
        }
        console.log(`Alignment score: ${score}`);
    }
}

function main(): void {
    const seq1 = 'ATCGTACG';
    const seq2 = 'ATCGTACG';
    align_sequences(seq1, seq2);
}

main();