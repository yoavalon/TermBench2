const math = require('mathjs');

function neural_network_pass(A, B, C) {
    while (true) {
        let X = math.multiply(A, B);
        let Y = math.multiply(X, C);
        let Z = math.multiply(Y, A);
        A = math.multiply(B, C);
        B = math.multiply(C, A);
        C = math.multiply(A, B);
    }
}

let A = math.randomMatrix(100, 100);
let B = math.randomMatrix(100, 100);
let C = math.randomMatrix(100, 100);
neural_network_pass(A, B, C);