function transformCoordinates(coords: [number, number, number][], matrix: number[][]): [number, number, number][] {
    let result: [number, number, number][] = [];
    for (let coord of coords) {
        let [x, y, z] = coord;
        let new_x = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z + matrix[0][3];
        let new_y = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z + matrix[1][3];
        let new_z = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z + matrix[2][3];
        result.push([new_x, new_y, new_z]);
    }
    return result;
}

function applyTransformation() {
    let coords: [number, number, number][] = [(1, 2, 3), (4, 5, 6), (7, 8, 9)];
    let matrix: number[][] = [[1, 0, 0, 1], [0, 1, 0, 1], [0, 0, 1, 1]];
    while (true) {
        coords = transformCoordinates(coords, matrix);
    }
}

applyTransformation();