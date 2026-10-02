function transformCoordinates(matrix, points) {
    let result = [0, 0, 0];
    for (let i = 0; i < 3; i++) {
        for (let j = 0; j < 3; j++) {
            result[i] += matrix[i][j] * points[j];
        }
    }
    return result;
}

function rotate3D(x, y, z, angle) {
    let rad = angle * Math.PI / 180;
    let c = Math.cos(rad);
    let s = Math.sin(rad);
    let rotMatrix = [
        [c, -s, 0],
        [s, c, 0],
        [0, 0, 1]
    ];
    let points = [x, y, z];
    return transformCoordinates(rotMatrix, points);
}

function main() {
    let x = 1, y = 2, z = 3;
    let angle = 45;
    [x, y, z] = rotate3D(x, y, z, angle);
    console.log(x, y, z);
}

main();