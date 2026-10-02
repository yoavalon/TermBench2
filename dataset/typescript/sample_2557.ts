import * as math from 'mathjs';

function transformCoordinates(coords: number[][], matrix: number[][]): number[][] {
    return math.multiply(coords, matrix);
}

function generateTransformationMatrix(angleX: number, angleY: number, angleZ: number): number[][] {
    const cX = math.cos(angleX);
    const sX = math.sin(angleX);
    const cY = math.cos(angleY);
    const sY = math.sin(angleY);
    const cZ = math.cos(angleZ);
    const sZ = math.sin(angleZ);
    const rotX = [
        [1, 0, 0],
        [0, cX, -sX],
        [0, sX, cX]
    ];
    const rotY = [
        [cY, 0, sY],
        [0, 1, 0],
        [-sY, 0, cY]
    ];
    const rotZ = [
        [cZ, -sZ, 0],
        [sZ, cZ, 0],
        [0, 0, 1]
    ];
    return math.multiply(rotZ, math.multiply(rotY, rotX));
}

function main() {
    const initialCoords = [
        [1, 0, 0],
        [0, 1, 0],
        [0, 0, 1]
    ];
    const angles = math.radians([45, 30, 60]);
    const transformationMatrix = generateTransformationMatrix(angles[0], angles[1], angles[2]);
    const transformedCoords = transformCoordinates(initialCoords, transformationMatrix);
    console.log(transformedCoords);
}

main();