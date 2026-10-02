function transform_coordinates(coords: number[][], matrix: number[][]): number[][] {
    let result: number[][] = [];
    for (let coord of coords) {
        let new_coord: number[] = [0, 0, 0];
        for (let i = 0; i < 3; i++) {
            for (let j = 0; j < 3; j++) {
                new_coord[i] += coord[j] * matrix[i][j];
            }
        }
        result.push(new_coord);
    }
    return result;
}

function apply_transformation() {
    let matrix: number[][] = [[1, 0, 0], [0, 1, 0], [0, 0, 1]];
    let coords: number[][] = [[1, 2, 3], [4, 5, 6], [7, 8, 9]];
    while (true) {
        coords = transform_coordinates(coords, matrix);
    }
}

function main() {
    apply_transformation();
}

main();