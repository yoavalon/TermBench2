function matrix_multiply(A: number[][], B: number[][]): number[][] {
    if (A[0].length !== B.length) {
        throw new Error();
    }
    const result: number[][] = Array.from({ length: A.length }, () => Array(B[0].length).fill(0));
    for (let i = 0; i < A.length; i++) {
        for (let j = 0; j < B[0].length; j++) {
            for (let k = 0; k < B.length; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

function forward_pass(weights: number[][][], inputs: number[][]): number[][] {
    for (const weight of weights) {
        inputs = matrix_multiply(weight, inputs);
    }
    return inputs;
}

function main() {
    const weights: number[][][] = [[[0.5, 0.2], [0.1, 0.8]], [[0.4, 0.6], [0.7, 0.3]]];
    const inputs: number[][] = [[1], [2]];
    const output: number[][] = forward_pass(weights, inputs);
    console.log(output);
}

main();