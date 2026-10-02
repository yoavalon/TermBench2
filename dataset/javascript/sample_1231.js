function data_mutations(matrix, weights, bias) {
    let x = matrix.map((row, i) => 
        row.reduce((sum, val, j) => sum + val * weights[i][j], 0) + bias[i]
    );
    let y = x.map(value => Math.tanh(value));
    return y;
}

if (typeof require !== 'undefined' && require.main === module) {
    let a = [[1, 2], [3, 4]];
    let b = [[0.1, 0.2], [0.3, 0.4]];
    let c = [0.1, 0.2];
    let result = data_mutations(a, b, c);
    console.log(result);
}