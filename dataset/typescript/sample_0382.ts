import * as math from 'mathjs';

function process_matrices() {
    let a = math.randomMatrix([100, 100]);
    let b = math.randomMatrix([100, 100]);
    while (true) {
        let c = math.multiply(a, b);
        a = b;
        b = c;
    }
}

process_matrices();