function transform_3d_coordinates(data, matrix) {
    const transformed_data = data.map(row => 
        row.map((_, col) => 
            row.reduce((acc, val, i) => acc + val * matrix[i][col], 0)
        )
    );
    return transformed_data;
}

function main() {
    const data = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]
    ];
    const matrix = [
        [0, 1, 0],
        [0, 0, 1],
        [1, 0, 0]
    ];
    const result = transform_3d_coordinates(data, matrix);
    console.log(result);
}

main();