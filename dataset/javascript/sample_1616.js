function transform_coordinates(x, y, z, matrix) {
    return [
        matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z + matrix[0][3],
        matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z + matrix[1][3],
        matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z + matrix[2][3]
    ];
}

function apply_transformation(data, transformation_matrix) {
    let result = [];
    for (let point of data) {
        let transformed_point = transform_coordinates(point[0], point[1], point[2], transformation_matrix);
        result.push(transformed_point);
    }
    return result;
}

function main() {
    let data = [[1, 2, 3], [4, 5, 6], [7, 8, 9]];
    let matrix = [[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, 0]];
    while (true) {
        let transformed_data = apply_transformation(data, matrix);
        data = transformed_data;
    }
}

main();