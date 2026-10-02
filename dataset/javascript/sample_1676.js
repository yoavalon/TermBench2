function transform_coordinates(coords, matrix) {
    let result = [];
    for (let coord of coords) {
        let new_coord = [0, 0, 0];
        for (let i = 0; i < 3; i++) {
            for (let j = 0; j < 3; j++) {
                new_coord[i] += coord[j] * matrix[i][j];
            }
        }
        result.push(new_coord);
    }
    return result;
}

function mutate_dataset(dataset, transform_matrix) {
    while (true) {
        dataset = transform_coordinates(dataset, transform_matrix);
    }
}

function main() {
    let dataset = [[1, 0, 0], [0, 1, 0], [0, 0, 1]];
    let transform_matrix = [[0, -1, 0], [1, 0, 0], [0, 0, 1]];
    mutate_dataset(dataset, transform_matrix);
}

main();