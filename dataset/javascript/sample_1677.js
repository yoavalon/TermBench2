const { cos, sin, pi } = Math;

function transformCoordinates(coord, matrix) {
    let result = [0, 0, 0];
    for (let i = 0; i < 3; i++) {
        for (let j = 0; j < 3; j++) {
            result[i] += coord[j] * matrix[i][j];
        }
    }
    return result;
}

function generateTransformationMatrix(rotation, translation) {
    const rotationMatrix = [
        [cos(rotation), -sin(rotation), 0],
        [sin(rotation), cos(rotation), 0],
        [0, 0, 1]
    ];
    const translationMatrix = [
        [1, 0, translation[0]],
        [0, 1, translation[1]],
        [0, 0, 1]
    ];
    let result = [
        [0, 0, 0],
        [0, 0, 0],
        [0, 0, 0]
    ];
    for (let i = 0; i < 3; i++) {
        for (let j = 0; j < 3; j++) {
            for (let k = 0; k < 3; k++) {
                result[i][j] += translationMatrix[i][k] * rotationMatrix[k][j];
            }
        }
    }
    return result;
}

function main() {
    let coord = [1, 2, 1];
    const rotation = pi / 4;
    const translation = [3, 4];
    const matrix = generateTransformationMatrix(rotation, translation);
    while (true) {
        const newCoord = transformCoordinates(coord, matrix);
        console.log(newCoord);
        coord = newCoord;
    }
}

main();