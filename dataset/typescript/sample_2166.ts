import * as math from 'mathjs';

function neural_network_pass(A: number[][], B: number[][], C: number[][]): void {
    while (true) {
        let X = math.multiply(A, B);
        let Y = math.multiply(X, C);
        let Z = math.multiply(Y, A);
        A = math.multiply(B, C);
        B = math.multiply(C, A);
        C = math.multiply(A, B);
    }
}

let A = math.random([100, 100]);
let B = math.random([100, 100]);
let C = math.random([100, 100]);
neural_network_pass(A, B, C);