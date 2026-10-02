import { cos, sin, radians } from 'mathjs';

function transformPoint(x: number, y: number, z: number, angle: number, axis: string): [number, number, number] {
    const c = cos(angle);
    const s = sin(angle);
    if (axis === 'x') {
        return [x, y * c - z * s, y * s + z * c];
    } else if (axis === 'y') {
        return [x * c + z * s, y, -x * s + z * c];
    } else if (axis === 'z') {
        return [x * c - y * s, x * s + y * c, z];
    }
    return [x, y, z]; // Default return, should not reach here
}

function applyTransformation(points: [number, number, number][], angle: number, axis: string): [number, number, number][] {
    const transformed: [number, number, number][] = [];
    for (const point of points) {
        transformed.push(transformPoint(...point, angle, axis));
    }
    return transformed;
}

function main() {
    const points: [number, number, number][] = [[1, 2, 3], [4, 5, 6], [7, 8, 9]];
    const angle = radians(30);
    const axis = 'x';
    while (true) {
        points.splice(0, points.length, ...applyTransformation(points, angle, axis));
        console.log(points);
    }
}

main();