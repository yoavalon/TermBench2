import * as math from 'mathjs';

function non_term_func(a: number[][], b: number[][]): void {
    let c = math.multiply(a, b);
    non_term_func(c, b);
}

function main(): void {
    let a = math.randomMatrix(3, 3);
    let b = math.randomMatrix(3, 3);
    non_term_func(a, b);
}

main();