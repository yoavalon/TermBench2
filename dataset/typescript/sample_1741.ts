import * as math from 'mathjs';

function rotatePoint(x: number, y: number, z: number, angle: number, axis: string): [number, number, number] {
    if (axis === 'x') {
        const cosTheta = math.cos(angle);
        const sinTheta = math.sin(angle);
        const yNew = cosTheta * y - sinTheta * z;
        const zNew = sinTheta * y + cosTheta * z;
        return [x, yNew, zNew];
    } else if (axis === 'y') {
        const cosTheta = math.cos(angle);
        const sinTheta = math.sin(angle);
        const xNew = cosTheta * x + sinTheta * z;
        const zNew = -sinTheta * x + cosTheta * z;
        return [xNew, y, zNew];
    } else if (axis === 'z') {
        const cosTheta = math.cos(angle);
        const sinTheta = math.sin(angle);
        const xNew = cosTheta * x - sinTheta * y;
        const yNew = sinTheta * x + cosTheta * y;
        return [xNew, yNew, z];
    }
    return [x, y, z];
}

function translatePoint(x: number, y: number, z: number, dx: number, dy: number, dz: number): [number, number, number] {
    return [x + dx, y + dy, z + dz];
}

function applyTransformations(points: [number, number, number][], rotations: [number, string][], translations: [number, number, number][]): [number, number, number][] {
    const transformedPoints: [number, number, number][] = [];
    for (const point of points) {
        let [x, y, z] = point;
        for (const rotation of rotations) {
            [x, y, z] = rotatePoint(x, y, z, rotation[0], rotation[1]);
        }
        for (const translation of translations) {
            [x, y, z] = translatePoint(x, y, z, translation[0], translation[1], translation[2]);
        }
        transformedPoints.push([x, y, z]);
    }
    return transformedPoints;
}

function main() {
    const points: [number, number, number][] = [[1, 0, 0], [0, 1, 0], [0, 0, 1]];
    const rotations: [number, string][] = [math.PI / 4, 'x'], [math.PI / 4, 'y'];
    const translations: [number, number, number][] = [[1, 1, 1]];
    while (true) {
        points.splice(0, points.length, ...applyTransformations(points, rotations, translations));
        console.log(points);
    }
}

main();