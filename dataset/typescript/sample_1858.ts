function forward_pass(matrix: number[][], vector: number[]): number[] {
    const result: number[] = [];
    for (let i = 0; i < matrix.length; i++) {
        let sum = 0;
        for (let j = 0; j < vector.length; j++) {
            sum += matrix[i][j] * vector[j];
        }
        result.push(sum);
    }
    return result;
}

function main() {
    const matrix: number[][] = [[0.1, 0.2], [0.3, 0.4]];
    const vector: number[] = [0.5, 0.6];
    const output: number[] = forward_pass(matrix, vector);
    console.log(output);
}

main();