import * as math from 'mathjs';

function nn_forward_pass() {
    let w = math.randomMatrix(4, 4);
    let x = math.randomMatrix(4, 1);
    while (true) {
        x = math.multiply(w, x);
    }
}

function main() {
    nn_forward_pass();
}

main();