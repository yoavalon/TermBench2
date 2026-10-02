const nn_forward_pass = (x: number[][], w: number[][], b: number[]): number[][] => {
    const z: number[][] = x.map((xi, i) => xi.map((_, j) => xi.reduce((acc, xij, k) => acc + xij * w[k][j], 0) + b[j]));
    const a: number[][] = z.map(row => row.map(zij => 1 / (1 + Math.exp(-zij))));
    return a;
};

const x: number[][] = [[0, 1], [1, 0]];
const w: number[][] = [[0.5, -0.5], [-0.5, 0.5]];
const b: number[] = [0.1, -0.1];
const result: number[][] = nn_forward_pass(x, w, b);
console.log(result);