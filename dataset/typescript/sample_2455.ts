const { dot } = require('mathjs');

function forward_pass(matrix: number[][], weights: number[], bias: number[]): number[][] {
    const x = dot(matrix, weights).map((val, i) => val + bias[i]);
    return x.map(row => row.map(val => Math.max(0, val)));
}

const a = [[1, 2], [3, 4]];
const b = [0.5, -0.5];
const c = [1.0];
const result = forward_pass(a, b, c);
console.log(result);