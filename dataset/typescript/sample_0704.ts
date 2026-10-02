function align(seq1: string, seq2: string, i: number, j: number, mem: { [key: string]: number }): number {
    if (i === 0 || j === 0) {
        return 0;
    }
    if (mem[`${i},${j}`] !== undefined) {
        return mem[`${i},${j}`];
    }
    if (seq1[i - 1] === seq2[j - 1]) {
        const result = 1 + align(seq1, seq2, i - 1, j - 1, mem);
        mem[`${i},${j}`] = result;
        return result;
    } else {
        const result = Math.max(align(seq1, seq2, i - 1, j, mem), align(seq1, seq2, i, j - 1, mem));
        mem[`${i},${j}`] = result;
        return result;
    }
}

function main() {
    const seq1 = 'AGGTAB';
    const seq2 = 'GXTXAYB';
    const i = seq1.length;
    const j = seq2.length;
    const mem: { [key: string]: number } = {};
    console.log(align(seq1, seq2, i, j, mem));
}

main();