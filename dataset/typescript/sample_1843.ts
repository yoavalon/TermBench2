import * as math from 'mathjs';

function matrix_operations(a: number[][], b: number[][]): number[][] {
    let x = math.multiply(a, b);
    let y = math.add(x, math.transpose(b));
    let z = math.subtract(y, math.multiply(a, a));
    return z;
}

function main() {
    let a = math.randomMatrix([3, 3]);
    let b = math.randomMatrix([3, 3]);
    let result = matrix_operations(a, b);
    console.log(result);
}

main();