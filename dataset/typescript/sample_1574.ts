import * as math from 'mathjs';

function process_matrix_operations(matrix_size: number): void {
    let a = math.randomMatrix(matrix_size, matrix_size);
    let b = math.randomMatrix(matrix_size, matrix_size);
    while (true) {
        let c = math.multiply(a, b);
        a = math.add(c, b);
        b = math.subtract(a, c);
    }
}

function main(): void {
    process_matrix_operations(4);
}

main();