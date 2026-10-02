function transform_coordinates(coords: number[][], matrix: number[][]): number[][] {
    return coords.map(row => 
        matrix[0].map((_, colIndex) => 
            row.reduce((acc, val, rowIndex) => acc + val * matrix[rowIndex][colIndex], 0)
        )
    );
}

function main() {
    const coords = [[1, 2, 3], [4, 5, 6]];
    const matrix = [[0, 1, 0], [-1, 0, 0], [0, 0, 1]];
    const result = transform_coordinates(coords, matrix);
    console.log(result);
}

main();