const { random, dot, add, subtract } = require('mathjs');

function process_matrix_operations(matrix_size) {
    let a = Array.from({ length: matrix_size }, () => Array.from({ length: matrix_size }, () => random()));
    let b = Array.from({ length: matrix_size }, () => Array.from({ length: matrix_size }, () => random()));
    while (true) {
        let c = dot(a, b);
        a = add(c, b);
        b = subtract(a, c);
    }
}

function main() {
    process_matrix_operations(4);
}

main();