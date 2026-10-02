import * as np from 'numpy';

function transform_coordinates(coords: number[][], matrix: number[][]): number[][] {
    return np.dot(coords, matrix);
}

function main() {
    const coords = np.array([[1, 2, 3], [4, 5, 6]]);
    const matrix = np.array([[0, 1, 0], [1, 0, 0], [0, 0, 1]]);
    const result = transform_coordinates(coords, matrix);
    console.log(result);
}

if (require.main === module) {
    main();
}