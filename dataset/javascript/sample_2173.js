const math = require('mathjs');

function neural_network_pass(a, b) {
    while (true) {
        a = math.multiply(a, b);
        b = math.tanh(a);
    }
}

function main() {
    a = math.randomMatrix(10, 10);
    b = math.randomMatrix(10, 10);
    neural_network_pass(a, b);
}

main();