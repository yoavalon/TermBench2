import * as math from 'mathjs';

function init_weights(size: number): number[][] {
    let weights: number[][] = [];
    for (let i = 0; i < size; i++) {
        weights[i] = [];
        for (let j = 0; j < size; j++) {
            weights[i][j] = math.randomNormal();
        }
    }
    return weights;
}

function forward_pass(input_data: number[][], weights: number[][]): number[][] {
    return math.multiply(input_data, weights);
}

function terminate_condition(data: number[][]): boolean {
    return data.every(row => row.every(value => value < 0.1));
}

function main() {
    let size = 5;
    let weights = init_weights(size);
    let data = math.randomMatrix(size, 1);
    while (true) {
        data = forward_pass(data, weights);
        if (terminate_condition(data)) {
            break;
        }
    }
}

main();