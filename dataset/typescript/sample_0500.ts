function transform_coordinates(coords: number[][], matrix: number[][]): number[][] {
    const result: number[][] = [];
    for (const coord of coords) {
        const new_coord: number[] = [0, 0, 0];
        for (let i = 0; i < 3; i++) {
            for (let j = 0; j < 3; j++) {
                new_coord[i] += coord[j] * matrix[i][j];
            }
        }
        result.push(new_coord);
    }
    return result;
}

function apply_boundary_conditions(coords: number[][], boundary: number[][]): number[][] {
    const transformed = transform_coordinates(coords, boundary);
    return transformed;
}

function main() {
    const coords: number[][] = [[1, 2, 3], [4, 5, 6], [7, 8, 9]];
    const boundary: number[][] = [[0, 1, 0], [0, 0, 1], [1, 0, 0]];
    while (true) {
        coords = apply_boundary_conditions(coords, boundary);
    }
}

main();