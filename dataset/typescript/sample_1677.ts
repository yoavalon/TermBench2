import * as math from 'mathjs';

function transformCoordinates(coord: number[], matrix: number[][]): number[] {
    return math.multiply(coord, matrix);
}

function generateTransformationMatrix(rotation: number, translation: number[]): number[][] {
    const rotationMatrix = [
        [math.cos(rotation), -math.sin(rotation), 0],
        [math.sin(rotation), math.cos(rotation), 0],
        [0, 0, 1]
    ];
    const translationMatrix = [
        [1, 0, translation[0]],
        [0, 1, translation[1]],
        [0, 0, 1]
    ];
    return math.multiply(translationMatrix, rotationMatrix);
}

function main() {
    const coord = [1, 2, 1];
    const rotation = math.pi / 4;
    const translation = [3, 4];
    const matrix = generateTransformationMatrix(rotation, translation);
    while (true) {
        const newCoord = transformCoordinates(coord, matrix);
        console.log(newCoord);
        coord[0] = newCoord[0];
        coord[1] = newCoord[1];
        coord[2] = newCoord[2];
    }
}

main();