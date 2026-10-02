function optimize_supply_chain(data: number[][], epsilon: number): number[][] {
    const a = data;
    const n = a.length;
    const m = a[0].length;
    const identity = Array.from({ length: m }, (_, i) => Array.from({ length: m }, (_, j) => i === j ? 1 : 0));
    const aTranspose = Array.from({ length: m }, () => Array.from({ length: n }, () => 0));
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            aTranspose[i][j] = a[j][i];
        }
    }
    const ataPlusEpsilonI = Array.from({ length: m }, () => Array.from({ length: m }, () => 0));
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < m; j++) {
            ataPlusEpsilonI[i][j] = aTranspose[i].reduce((sum, val, k) => sum + val * a[k][j], 0) + (i === j ? epsilon : 0);
        }
    }
    const ataPlusEpsilonIInverse = Array.from({ length: m }, () => Array.from({ length: m }, () => 0));
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < m; j++) {
            ataPlusEpsilonIInverse[i][j] = ataPlusEpsilonI[i][j];
        }
    }
    const c = Array.from({ length: m }, () => Array.from({ length: n }, () => 0));
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            c[i][j] = ataPlusEpsilonIInverse[i].reduce((sum, val, k) => sum + val * aTranspose[k][j], 0);
        }
    }
    return c;
}

const data = [[1.0001, 2.0002], [3.0003, 4.0004]];
const epsilon = 0.0001;
const result = optimize_supply_chain(data, epsilon);
console.log(result);