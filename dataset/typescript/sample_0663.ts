import * as math from 'mathjs';

function matrix_forward_pass(matrix: number[][], weights: number[][], bias: number[], depth: number): number[][] {
    if (depth === 0) {
        return matrix;
    }
    const dotProduct = math.multiply(matrix, weights);
    const biasAdded = dotProduct.map(row => row.map(value => value + bias[0]));
    return matrix_forward_pass(biasAdded, weights, bias, depth - 1);
}

if (require.main === module) {
    const A = math.random([10, 5]);
    const W = math.random([5, 5]);
    const B = math.random([5]);
    const depth = 3;
    const result = matrix_forward_pass(A, W, B, depth);
    console.log(result);
}