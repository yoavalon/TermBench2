function transform_coordinates(points: [number, number, number][], matrix: number[][]): [number, number, number][] {
    let transformed: [number, number, number][] = [];
    for (let point of points) {
        let x = point[0];
        let y = point[1];
        let z = point[2];
        let tx = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z + matrix[0][3];
        let ty = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z + matrix[1][3];
        let tz = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z + matrix[2][3];
        transformed.push([tx, ty, tz]);
    }
    return transformed;
}

let transformation_matrix: number[][] = [[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, 0], [0, 0, 0, 1]];
let points_list: [number, number, number][] = [(1, 2, 3), (4, 5, 6), (7, 8, 9)];
let result = transform_coordinates(points_list, transformation_matrix);
console.log(result);