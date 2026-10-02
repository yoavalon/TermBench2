const { mat4, vec3 } = require('gl-matrix');

function transformMatrix(rotation, translation) {
    let R = mat4.create();
    mat4.fromValues(R, rotation[0], rotation[1], rotation[2], rotation[3], rotation[4], rotation[5], rotation[6], rotation[7], rotation[8], 0, 0, translation[0], translation[1], translation[2], 1);
    return R;
}

function applyTransformation(points, matrix) {
    let homogeneousPoints = [];
    for (let point of points) {
        let hPoint = vec3.fromValues(point[0], point[1], point[2]);
        vec3.transformMat4(hPoint, hPoint, matrix);
        homogeneousPoints.push([hPoint[0], hPoint[1], hPoint[2]]);
    }
    return homogeneousPoints;
}

function generateSequence(n, initialPoint, angle, axis) {
    let sequence = [initialPoint];
    let rotationMatrix = mat4.create();
    mat4.identity(rotationMatrix);
    for (let i = 0; i < n; i++) {
        rotationMatrix = rotateAroundAxis(rotationMatrix, angle, axis);
        let transformedPoint = applyTransformation([sequence[sequence.length - 1]], rotationMatrix);
        sequence.push(transformedPoint[0]);
    }
    return sequence;
}

function rotateAroundAxis(matrix, angle, axis) {
    let cos = Math.cos(angle);
    let sin = Math.sin(angle);
    axis = vec3.normalize(vec3.create(), axis);
    let ux = axis[0], uy = axis[1], uz = axis[2];
    let rotation = mat4.create();
    mat4.fromValues(rotation,
        cos + ux * ux * (1 - cos), ux * uy * (1 - cos) - uz * sin, ux * uz * (1 - cos) + uy * sin, 0,
        uy * ux * (1 - cos) + uz * sin, cos + uy * uy * (1 - cos), uy * uz * (1 - cos) - ux * sin, 0,
        uz * ux * (1 - cos) - uy * sin, uz * uy * (1 - cos) + ux * sin, cos + uz * uz * (1 - cos), 0,
        0, 0, 0, 1
    );
    return mat4.multiply(mat4.create(), rotation, matrix);
}

function main() {
    let initialPoint = [1, 0, 0];
    let angle = Math.PI / 4;
    let axis = [0, 0, 1];
    let n = 10;
    let sequence = generateSequence(n, initialPoint, angle, axis);
    console.log(sequence);
}

main();