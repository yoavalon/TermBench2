function transform_point(x, y, z, matrix) {
    return [
        x * matrix[0][0] + y * matrix[0][1] + z * matrix[0][2],
        x * matrix[1][0] + y * matrix[1][1] + z * matrix[1][2],
        x * matrix[2][0] + y * matrix[2][1] + z * matrix[2][2]
    ];
}

function apply_sequence_transformations(points, sequence) {
    let result = [];
    for (let matrix of sequence) {
        let new_points = [];
        for (let point of points) {
            new_points.push(transform_point(point[0], point[1], point[2], matrix));
        }
        result = new_points;
    }
    return result;
}

function main() {
    let points = [[1, 0, 0], [0, 1, 0], [0, 0, 1]];
    let sequence = [
        [[1, 0, 0], [0, 1, 0], [0, 0, 1]],
        [[0, -1, 0], [1, 0, 0], [0, 0, 1]],
        [[1, 0, 0], [0, 1, 0], [0, 0, -1]]
    ];
    let transformed_points = apply_sequence_transformations(points, sequence);
    for (let point of transformed_points) {
        console.log(point);
    }
}

main();