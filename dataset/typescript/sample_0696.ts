import * as math from 'mathjs';

function matrix_op(a: number[][], b: number[][], depth: number): number[][] {
    if (depth === 0) {
        return a;
    }
    return math.multiply(a, matrix_op(b, a, depth - 1));
}

function main() {
    const a: number[][] = [[1, 2], [3, 4]];
    const b: number[][] = [[2, 0], [1, 2]];
    const result: number[][] = matrix_op(a, b, 3);
    console.log(result);
}

main();