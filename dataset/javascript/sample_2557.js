const math = require('mathjs');

function transformCoordinates(coords, matrix) {
    return math.multiply(coords, matrix);
}

function generateTransformationMatrix(angleX, angleY, angleZ) {
    const cX = math.cos(angleX);
    const sX = math.sin(angleX);
    const cY = math.cos(angleY);
    const sY = math.sin(angleY);
    const cZ = math.cos(angleZ);
    const sZ = math.sin(angleZ);
    const rotX = math.matrix([[1, 0, 0], [0, cX, -sX], [0, sX, cX]]);
    const rotY = math.matrix([[cY, 0, sY], [0, 1, 0], [-sY, 0, cY]]);
    const rotZ = math.matrix([[cZ, -sZ, 0], [sZ, cZ, 0], [0, 0, 1]]);
    return math.multiply(rotZ, math.multiply(rotY, rotX));
}

function main() {
    const initialCoords = math.matrix([[1, 0, 0], [0, 1, 0], [0, 0, 1]]);
    const angles = math.degToRad([45, 30, 60]);
    const transformationMatrix = generateTransformationMatrix(angles[0], angles[1], angles[2]);
    const transformedCoords = transformCoordinates(initialCoords, transformationMatrix);
    console.log(transformedCoords);
}

main();