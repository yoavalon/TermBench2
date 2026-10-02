function transform_coordinates(coords: [number, number, number][], matrix: number[][]): [number, number, number][] {
    const result: [number, number, number][] = [];
    for (const coord of coords) {
        const [x, y, z] = coord;
        const new_x = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z + matrix[0][3];
        const new_y = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z + matrix[1][3];
        const new_z = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z + matrix[2][3];
        result.push([new_x, new_y, new_z]);
    }
    return result;
}

const matrix = [[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, 0], [0, 0, 0, 1]];
const coords = [(1, 2, 3), (4, 5, 6)];
const new_coords = transform_coordinates(coords, matrix);
console.log(new_coords);