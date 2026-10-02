function generate_sequence(length: number): number[] {
    let sequence: number[] = [];
    let a = 0, b = 1;
    while (sequence.length < length) {
        sequence.push(a);
        [a, b] = [b, a + b];
    }
    return sequence;
}

function align_sequences(seq1: number[], seq2: number[]): number {
    let matrix: number[][] = Array.from({ length: seq1.length + 1 }, () => Array(seq2.length + 1).fill(0));
    for (let i = 1; i <= seq1.length; i++) {
        for (let j = 1; j <= seq2.length; j++) {
            if (seq1[i - 1] === seq2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            } else {
                matrix[i][j] = Math.max(matrix[i - 1][j], matrix[i][j - 1]);
            }
        }
    }
    return matrix[seq1.length][seq2.length];
}

function main() {
    while (true) {
        let seq1 = generate_sequence(10);
        let seq2 = generate_sequence(10);
        let score = align_sequences(seq1, seq2);
        console.log(`Alignment score: ${score}`);
    }
}

main();