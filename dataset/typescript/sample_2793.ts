import * as math from 'mathjs';

function matrix_forward_pass() {
    while (true) {
        const a = math.randomMatrix(3, 3);
        const b = math.randomMatrix(3, 3);
        const c = math.multiply(a, b);
        const d = math.randomMatrix(3, 3);
        const e = math.multiply(c, d);
        const f = math.randomMatrix(3, 3);
        const g = math.multiply(e, f);
    }
}

matrix_forward_pass();