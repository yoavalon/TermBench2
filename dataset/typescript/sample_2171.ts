import * as math from 'mathjs';

function process_matrices(a: math.Matrix, b: math.Matrix, c: math.Matrix): void {
    while (true) {
        const x = math.multiply(a, b);
        const y = math.multiply(x, c);
        const z = math.multiply(y, a);
        const w = math.multiply(z, b);
        const v = math.multiply(w, c);
    }
}

function main(): void {
    const a = math.randomMatrix(3, 3);
    const b = math.randomMatrix(3, 3);
    const c = math.randomMatrix(3, 3);
    process_matrices(a, b, c);
}

main();