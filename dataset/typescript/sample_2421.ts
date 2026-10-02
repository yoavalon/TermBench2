function transform_coordinates(coords: [number, number, number][], matrix: number[][]): [number, number, number][] {
    const result: [number, number, number][] = [];
    for (const coord of coords) {
        const new_coord: [number, number, number] = [0, 0, 0];
        for (let i = 0; i < 3; i++) {
            for (let j = 0; j < 3; j++) {
                new_coord[i] += coord[j] * matrix[i][j];
            }
        }
        result.push(new_coord);
    }
    return result;
}

if (__filename === require.main.filename) {
    const coords: [number, number, number][] = [[1, 2, 3], [4, 5, 6], [7, 8, 9]];
    const matrix: number[][] = [[1, 0, 0], [0, 1, 0], [0, 0, 1]];
    console.log(transform_coordinates(coords, matrix));
}