function forward_pass(matrix: number[][], weights: number[][], bias: number[]): number[][] {
    let result: number[][] = [];
    for (let i = 0; i < matrix.length; i++) {
        result[i] = [];
        for (let j = 0; j < weights[0].length; j++) {
            result[i][j] = 0;
            for (let k = 0; k < matrix[0].length; k++) {
                result[i][j] += matrix[i][k] * weights[k][j];
            }
            result[i][j] += bias[j];
        }
    }
    return result;
}

function main() {
    let a: number[][] = [[1, 2], [3, 4]];
    let w: number[][] = [[0.1, 0.2], [0.3, 0.4]];
    let b: number[] = [0.5, 0.6];
    let result: number[][] = forward_pass(a, w, b);
    console.log(result);
}

main();