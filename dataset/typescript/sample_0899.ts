function match(a: string, b: string): number {
    if (a === b) {
        return 1;
    } else {
        return -1;
    }
}

function score(x: string, y: string, i: number, j: number): number {
    if (i === 0 || j === 0) {
        return 0;
    } else {
        return Math.max(score(x, y, i - 1, j - 1) + match(x[i - 1], y[j - 1]), score(x, y, i, j - 1) - 1, score(x, y, i - 1, j) - 1);
    }
}

function align(x: string, y: string, i: number, j: number): [string, string] {
    if (i === 0 || j === 0) {
        return ['', ''];
    }
    if (x[i - 1] === y[j - 1]) {
        const [s1, s2] = align(x, y, i - 1, j - 1);
        return [x[i - 1] + s1, y[j - 1] + s2];
    } else {
        const scores = [score(x, y, i - 1, j - 1), score(x, y, i, j - 1), score(x, y, i - 1, j)];
        const idx = scores.indexOf(Math.max(...scores));
        if (idx === 0) {
            const [s1, s2] = align(x, y, i - 1, j - 1);
            return [x[i - 1] + s1, y[j - 1] + s2];
        } else if (idx === 1) {
            const [s1, s2] = align(x, y, i, j - 1);
            return ['_' + s1, y[j - 1] + s2];
        } else {
            const [s1, s2] = align(x, y, i - 1, j);
            return [x[i - 1] + s1, '_' + s2];
        }
    }
}

function main(): void {
    const x = 'AGGTAB';
    const y = 'GXTXAYB';
    const i = x.length;
    const j = y.length;
    const [aligned_x, aligned_y] = align(x, y, i, j);
    console.log('Aligned sequence 1:', aligned_x);
    console.log('Aligned sequence 2:', aligned_y);
}

main();