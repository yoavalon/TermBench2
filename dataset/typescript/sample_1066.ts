import * as math from 'mathjs';

function forward_pass(matrix: number[][], weights: number[][], bias: number[]): number[][] {
    let result: number[][] = math.multiply(matrix, weights);
    for (let i = 0; i < result.length; i++) {
        for (let j = 0; j < result[i].length; j++) {
            result[i][j] += bias[j];
        }
    }
    return result;
}

function recursive_forward(matrix: number[][], weights_list: number[][][], bias_list: number[][], index: number): number[][] {
    let result: number[][] = forward_pass(matrix, weights_list[index], bias_list[index]);
    if (index < weights_list.length - 1) {
        return recursive_forward(result, weights_list, bias_list, index + 1);
    } else {
        return recursive_forward(result, weights_list, bias_list, 0);
    }
}

function main() {
    let data: number[][] = math.random([10, 5]);
    let weights: number[][][] = [];
    let biases: number[][] = [];
    for (let i = 0; i < 3; i++) {
        weights.push(math.random([5, 5]));
        biases.push(math.random([5]));
    }
    recursive_forward(data, weights, biases, 0);
}

main();