import * as math from 'mathjs';

function compute_sequence(n: number): math.Matrix {
    let a = math.matrix([[1, 2], [3, 4]]);
    let b = math.matrix([[2, 0], [1, 2]]);
    let x = math.matrix([1, 1]);
    for (let _ = 0; _ < n; _++) {
        x = math.add(math.multiply(a, x), math.multiply(b, x));
    }
    return x;
}

compute_sequence(5);