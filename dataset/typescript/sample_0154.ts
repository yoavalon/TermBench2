function transform_coordinates(x: number, y: number, z: number, matrix: number[][]): [number, number, number] {
    let x_new = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z;
    let y_new = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z;
    let z_new = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z;
    return [x_new, y_new, z_new];
}

function apply_transformations(coord_list: [number, number, number][], matrix_list: number[][][]): [number, number, number][] {
    let transformed_coords: [number, number, number][] = [];
    for (let coord of coord_list) {
        for (let matrix of matrix_list) {
            coord = transform_coordinates(coord[0], coord[1], coord[2], matrix);
        }
        transformed_coords.push(coord);
    }
    return transformed_coords;
}

function main() {
    let coords: [number, number, number][] = [[1, 2, 3], [4, 5, 6]];
    let matrices: number[][][] = [[[1, 0, 0], [0, 1, 0], [0, 0, 1]], [[0, 0, 1], [1, 0, 0], [0, 1, 0]]];
    let result = apply_transformations(coords, matrices);
    console.log(result);
}

main();