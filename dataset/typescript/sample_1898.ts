function transform_3d(point: number[], matrix: number[][]): number[] {
    let result: number[] = [0, 0, 0];
    for (let i = 0; i < 3; i++) {
        for (let j = 0; j < 3; j++) {
            result[i] += point[j] * matrix[i][j];
        }
    }
    return result;
}

function main() {
    let point: number[] = [1.0, 2.0, 3.0];
    let matrix: number[][] = [[0, 1, 0], [0, 0, 1], [1, 0, 0]];
    let transformed: number[] = transform_3d(point, matrix);
    console.log(transformed);
}

main();