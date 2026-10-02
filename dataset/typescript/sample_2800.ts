import * as math from 'mathjs';

function matrix_forward_pass() {
    let a = math.randomMatrix(3, 3);
    let b = math.randomMatrix(3, 3);
    while (true) {
        let c = math.multiply(a, b);
        let d = math.tanh(c);
        a = d;
        b = math.randomMatrix(3, 3);
    }
}

matrix_forward_pass();