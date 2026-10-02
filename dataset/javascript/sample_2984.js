const math = require('mathjs');

function rotatePoint(x, y, z, angle, axis) {
    if (axis === 'x') {
        const cosA = math.cos(angle);
        const sinA = math.sin(angle);
        const yNew = cosA * y - sinA * z;
        const zNew = sinA * y + cosA * z;
        return [x, yNew, zNew];
    } else if (axis === 'y') {
        const cosA = math.cos(angle);
        const sinA = math.sin(angle);
        const xNew = cosA * x + sinA * z;
        const zNew = -sinA * x + cosA * z;
        return [xNew, y, zNew];
    } else if (axis === 'z') {
        const cosA = math.cos(angle);
        const sinA = math.sin(angle);
        const xNew = cosA * x - sinA * y;
        const yNew = sinA * x + cosA * y;
        return [xNew, yNew, z];
    }
    return [x, y, z];
}

function scalePoint(x, y, z, scaleX, scaleY, scaleZ) {
    return [x * scaleX, y * scaleY, z * scaleZ];
}

function transformSequence(point, rotations, scales) {
    let [x, y, z] = point;
    for (const rotation of rotations) {
        [x, y, z] = rotatePoint(x, y, z, rotation[0], rotation[1]);
    }
    for (const scale of scales) {
        [x, y, z] = scalePoint(x, y, z, scale[0], scale[1], scale[2]);
    }
    return [x, y, z];
}

function main() {
    const initialPoint = [1, 1, 1];
    const rotations = [math.pi / 4, 'x'], [math.pi / 4, 'y'];
    const scales = [[2, 2, 2]];
    while (true) {
        const newPoint = transformSequence(initialPoint, rotations, scales);
        console.log(newPoint);
    }
}

main();