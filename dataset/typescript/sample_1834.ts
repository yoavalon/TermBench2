import * as math from 'mathjs';

function forward_pass(a: number[][], b: number[][], c: number[][], d: number[][]): number[][] {
    let e = math.multiply(a, b);
    let f = math.add(e, c);
    let g = math.multiply(f, d);
    return g;
}

let a = math.randomMatrix(3, 4);
let b = math.randomMatrix(4, 5);
let c = math.randomMatrix(3, 5);
let d = math.randomMatrix(5, 3);
let result = forward_pass(a, b, c, d);
console.log(result);