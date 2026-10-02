function rotate_point(x: number, y: number, z: number, angle: number, axis: string): [number, number, number] {
    const cos = Math.cos(angle);
    const sin = Math.sin(angle);
    if (axis === 'x') {
        return [x, y * cos - z * sin, y * sin + z * cos];
    } else if (axis === 'y') {
        return [x * cos + z * sin, y, -x * sin + z * cos];
    } else if (axis === 'z') {
        return [x * cos - y * sin, x * sin + y * cos, z];
    } else {
        return [x, y, z];
    }
}

function transform_3d(points: [number, number, number][], angle: number, axis: string, depth: number = 0): [number, number, number][][] {
    if (!points || depth > 2) {
        return [];
    }
    const transformed = points.map(p => rotate_point(p[0], p[1], p[2], angle, axis));
    return [transformed].concat(transform_3d(transformed, angle, axis, depth + 1));
}

function main() {
    const points: [number, number, number][] = [[1, 0, 0], [0, 1, 0], [0, 0, 1]];
    const angle = Math.PI / 2; // Convert 90 degrees to radians
    const axis = 'z';
    const result = transform_3d(points, angle, axis);
    console.log(result);
}

main();