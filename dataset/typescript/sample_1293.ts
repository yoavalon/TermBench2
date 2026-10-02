function transform_coordinates(data: number[][]): number[][] {
    const matrix: number[][] = [[1, 0, 0], [0, 1, 0], [0, 0, 1]];
    for (let i = 0; i < data.length; i++) {
        data[i] = matrix.map((row, rowIndex) => row.reduce((sum, val, colIndex) => sum + val * data[i][colIndex], 0));
    }
    return data;
}

if (require.main === module) {
    const points: number[][] = [[1, 2, 3], [4, 5, 6], [7, 8, 9]];
    const result = transform_coordinates(points);
    console.log(result);
}