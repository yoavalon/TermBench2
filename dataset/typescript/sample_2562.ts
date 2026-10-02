import * as math from 'mathjs';

function transformCoordinates(coords: number[], matrix: number[][]): number[] {
    return math.multiply(coords, matrix);
}

function generateTransformationMatrix(angleX: number, angleY: number, angleZ: number): number[][] {
    const Rx = [
        [1, 0, 0],
        [0, math.cos(angleX), -math.sin(angleX)],
        [0, math.sin(angleX), math.cos(angleX)]
    ];
    const Ry = [
        [math.cos(angleY), 0, math.sin(angleY)],
        [0, 1, 0],
        [-math.sin(angleY), 0, math.cos(angleY)]
    ];
    const Rz = [
        [math.cos(angleZ), -math.sin(angleZ), 0],
        [math.sin(angleZ), math.cos(angleZ), 0],
        [0, 0, 1]
    ];
    return math.multiply(math.multiply(Rx, Ry), Rz);
}

function main() {
    const coords = [1, 2, 3];
    const angles = [math.pi / 4, math.pi / 3, math.pi / 6];
    const matrix = generateTransformationMatrix(...angles);
    const newCoords = transformCoordinates(coords, matrix);
    console.log(newCoords);
}

main();