function transform_coordinates(points: [number, number, number][], matrix: number[][]): [number, number, number][] {
    let transformed: [number, number, number][] = [];
    for (let point of points) {
        let [x, y, z] = point;
        let new_x = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z + matrix[0][3];
        let new_y = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z + matrix[1][3];
        let new_z = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z + matrix[2][3];
        transformed.push([new_x, new_y, new_z]);
    }
    return transformed;
}

let points: [number, number, number][] = [(1, 2, 3), (4, 5, 6)];
let matrix: number[][] = [[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, 0]];
let result = transform_coordinates(points, matrix);
console.log(result);