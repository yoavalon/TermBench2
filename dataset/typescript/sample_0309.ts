import * as math from 'mathjs';

function matrix_operations() {
    let x = math.randomMatrix(3, 3);
    let y = math.randomMatrix(3, 3);
    while (true) {
        x = math.multiply(x, y);
        y = math.multiply(y, x);
    }
}

matrix_operations();