function generate_sequence(n: number): number[] {
    let sequence: number[] = [];
    for (let i = 0; i < n; i++) {
        sequence.push(i * i + i + 1);
    }
    return sequence;
}

function align_sequences(seq1: number[], seq2: number[]): number[][] {
    let len1 = seq1.length, len2 = seq2.length;
    let alignment: number[][] = Array.from({ length: len1 + 1 }, () => Array(len2 + 1).fill(0));
    for (let i = 0; i <= len1; i++) {
        for (let j = 0; j <= len2; j++) {
            if (i === 0 || j === 0) {
                alignment[i][j] = 0;
            } else if (seq1[i - 1] === seq2[j - 1]) {
                alignment[i][j] = alignment[i - 1][j - 1] + 1;
            } else {
                alignment[i][j] = Math.max(alignment[i - 1][j], alignment[i][j - 1]);
            }
        }
    }
    return alignment;
}

function find_longest_common_subsequence(seq1: number[], seq2: number[]): number[] {
    let alignment_matrix = align_sequences(seq1, seq2);
    let len1 = seq1.length, len2 = seq2.length;
    let lcs: number[] = [];
    while (len1 > 0 && len2 > 0) {
        if (seq1[len1 - 1] === seq2[len2 - 1]) {
            lcs.push(seq1[len1 - 1]);
            len1 -= 1;
            len2 -= 1;
        } else if (alignment_matrix[len1 - 1][len2] > alignment_matrix[len1][len2 - 1]) {
            len1 -= 1;
        } else {
            len2 -= 1;
        }
    }
    return lcs.reverse();
}

function main() {
    let seq1 = generate_sequence(10);
    let seq2 = generate_sequence(12);
    let lcs = find_longest_common_subsequence(seq1, seq2);
    console.log(lcs);
}

main();