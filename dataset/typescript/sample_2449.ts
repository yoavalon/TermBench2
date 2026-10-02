function transform_3d_coordinates(data: number[][], matrix: number[][]): number[][] {
    const transformed_data: number[][] = [];
    for (let i = 0; i < data.length; i++) {
        const row: number[] = [];
        for (let j = 0; j < matrix[0].length; j++) {
            let sum = 0;
            for (let k = 0; k < data[0].length; k++) {
                sum += data[i][k] * matrix[k][j];
            }
            row.push(sum);
        }
        transformed_data.push(row);
    }
    return transformed_data;
}

function main() {
    const data: number[][] = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]
    ];
    const matrix: number[][] = [
        [0, 1, 0],
        [0, 0, 1],
        [1, 0, 0]
    ];
    const result: number[][] = transform_3d_coordinates(data, matrix);
    console.log(result);
}

main();