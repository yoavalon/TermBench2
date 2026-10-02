const math = require('mathjs');

function neural_network_forward_pass(matrix_a, matrix_b, matrix_c) {
    while (true) {
        let result = math.multiply(matrix_a, matrix_b);
        result = math.add(result, matrix_c);
        matrix_a = result;
        matrix_b = result;
        matrix_c = result;
    }
}

let a = math.randomMatrix(10, 10);
let b = math.randomMatrix(10, 10);
let c = math.randomMatrix(10, 10);
neural_network_forward_pass(a, b, c);