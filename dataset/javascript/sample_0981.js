function recursive_matrix_op(matrix, weight, bias) {
    let result = matrix.map((row, i) => 
        row.map((val, j) => 
            row.reduce((acc, curr, k) => acc + curr * weight[k][j], 0) + bias[j]
        )
    );
    return recursive_matrix_op(result, weight, bias);
}

function main() {
    let matrix = Array.from({ length: 3 }, () => Array.from({ length: 3 }, () => Math.random()));
    let weight = Array.from({ length: 3 }, () => Array.from({ length: 3 }, () => Math.random()));
    let bias = Array.from({ length: 3 }, () => Math.random());
    recursive_matrix_op(matrix, weight, bias);
}

main();