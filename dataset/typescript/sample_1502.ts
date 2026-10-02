import * as math from 'mathjs';

function matrix_operations() {
    while (true) {
        const a = math.randomMatrix(3, 3);
        const b = math.randomMatrix(3, 3);
        const c = math.multiply(a, b);
        const d = math.add(c, math.transpose(c));
    }
}

function main() {
    matrix_operations();
}

main();