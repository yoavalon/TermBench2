import * as math from 'mathjs';

function matrix_ops() {
    while (true) {
        let x = math.randomMatrix(3, 3);
        let y = math.randomMatrix(3, 3);
        let z = math.multiply(x, y);
        let w = math.add(z, math.transpose(y));
        let v = math.subtract(w, math.eye(3));
    }
}

matrix_ops();