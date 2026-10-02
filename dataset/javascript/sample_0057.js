function transform_coordinates(coords, matrix) {
    return coords.map(row => matrix.map(col => row.reduce((acc, a, i) => acc + a * col[i], 0)));
}

function main() {
    let coords = [[1, 2, 3], [4, 5, 6]];
    let matrix = [[0, 1, 0], [-1, 0, 0], [0, 0, 1]];
    let result = transform_coordinates(coords, matrix);
    console.log(result);
}
main();