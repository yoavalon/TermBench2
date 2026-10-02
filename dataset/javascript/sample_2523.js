function transform_coordinates(coords, matrix) {
    let result = [];
    for (let coord of coords) {
        let [x, y, z] = coord;
        let new_x = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z;
        let new_y = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z;
        let new_z = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z;
        result.push([new_x, new_y, new_z]);
    }
    return result;
}

function main() {
    let matrix = [[1, 2, 3], [0, 1, 4], [5, 6, 0]];
    let coords = [[1, 0, 0], [0, 1, 0], [0, 0, 1]];
    let transformed_coords = transform_coordinates(coords, matrix);
    for (let coord of transformed_coords) {
        console.log(coord);
    }
}

main();