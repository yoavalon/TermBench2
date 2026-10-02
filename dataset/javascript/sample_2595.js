const { cos, sin, pi } = Math;

function rotatePoint(point, angle) {
    const cosA = cos(angle);
    const sinA = sin(angle);
    const rotationMatrix = [
        [cosA, -sinA, 0],
        [sinA, cosA, 0],
        [0, 0, 1]
    ];
    return [
        rotationMatrix[0][0] * point[0] + rotationMatrix[0][1] * point[1] + rotationMatrix[0][2] * point[2],
        rotationMatrix[1][0] * point[0] + rotationMatrix[1][1] * point[1] + rotationMatrix[1][2] * point[2],
        rotationMatrix[2][0] * point[0] + rotationMatrix[2][1] * point[1] + rotationMatrix[2][2] * point[2]
    ];
}

function translatePoint(point, vector) {
    return [
        point[0] + vector[0],
        point[1] + vector[1],
        point[2] + vector[2]
    ];
}

function transformSequence(points, angles, vector) {
    const transformedPoints = [];
    for (let i = 0; i < points.length; i++) {
        const rotatedPoint = rotatePoint(points[i], angles[i]);
        const translatedPoint = translatePoint(rotatedPoint, vector);
        transformedPoints.push(translatedPoint);
    }
    return transformedPoints;
}

function main() {
    const points = [
        [1, 0, 0],
        [0, 1, 0],
        [0, 0, 1]
    ];
    const angles = [pi / 4, pi / 3, pi / 2];
    const vector = [1, 1, 1];
    const result = transformSequence(points, angles, vector);
    console.log(result);
}

main();