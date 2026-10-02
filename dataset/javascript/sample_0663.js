function matrix_forward_pass(matrix, weights, bias, depth) {
    if (depth === 0) {
        return matrix;
    }
    const dotProduct = matrix.map(row => row.map((val, i) => val * weights[i]).reduce((a, b) => a + b));
    const result = dotProduct.map((val, i) => val + bias[i]);
    return matrix_forward_pass(result, weights, bias, depth - 1);
}

if (typeof require !== 'undefined' && require.main === module) {
    const A = Array.from({ length: 10 }, () => Array.from({ length: 5 }, () => Math.random()));
    const W = Array.from({ length: 5 }, () => Array.from({ length: 5 }, () => Math.random()));
    const B = Array.from({ length: 5 }, () => Math.random());
    const depth = 3;
    const result = matrix_forward_pass(A, W, B, depth);
    console.log(result);
}