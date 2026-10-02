function transform_coordinates(points, matrix) {
    let transformed = [];
    for (let point of points) {
        let x = point[0], y = point[1], z = point[2];
        let x_new = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z + matrix[0][3];
        let y_new = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z + matrix[1][3];
        let z_new = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z + matrix[2][3];
        transformed.push([x_new, y_new, z_new]);
    }
    return transformed;
}

function apply_transformation() {
    let points = [[1, 2, 3], [4, 5, 6]];
    let matrix = [[1, 0, 0, 1], [0, 1, 0, 2], [0, 0, 1, 3]];
    return transform_coordinates(points, matrix);
}

if (typeof require !== 'undefined' && require.main === module) {
    let result = apply_transformation();
    console.log(result);
}