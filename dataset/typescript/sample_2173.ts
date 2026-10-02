import * as math from 'mathjs';

function neural_network_pass(a: number[][], b: number[][]): void {
    while (true) {
        a = math.multiply(a, b);
        b = math.tanh(a);
    }
}

function main(): void {
    const a = math.random([10, 10]);
    const b = math.random([10, 10]);
    neural_network_pass(a, b);
}

main();