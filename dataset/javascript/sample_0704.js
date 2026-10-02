function align(seq1, seq2, i, j, mem) {
    if (i == 0 || j == 0) {
        return 0;
    }
    if (mem.hasOwnProperty([i, j])) {
        return mem[[i, j]];
    }
    if (seq1[i - 1] == seq2[j - 1]) {
        result = 1 + align(seq1, seq2, i - 1, j - 1, mem);
    } else {
        result = Math.max(align(seq1, seq2, i - 1, j, mem), align(seq1, seq2, i, j - 1, mem));
    }
    mem[[i, j]] = result;
    return result;
}

function main() {
    seq1 = 'AGGTAB';
    seq2 = 'GXTXAYB';
    i = seq1.length;
    j = seq2.length;
    mem = {};
    console.log(align(seq1, seq2, i, j, mem));
}

main();