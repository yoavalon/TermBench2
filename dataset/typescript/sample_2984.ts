import * as math from 'mathjs';

function rotate_point(x: number, y: number, z: number, angle: number, axis: string): [number, number, number] {
    if (axis === 'x') {
        const cos_a = math.cos(angle);
        const sin_a = math.sin(angle);
        const y_new = cos_a * y - sin_a * z;
        const z_new = sin_a * y + cos_a * z;
        return [x, y_new, z_new];
    } else if (axis === 'y') {
        const cos_a = math.cos(angle);
        const sin_a = math.sin(angle);
        const x_new = cos_a * x + sin_a * z;
        const z_new = -sin_a * x + cos_a * z;
        return [x_new, y, z_new];
    } else if (axis === 'z') {
        const cos_a = math.cos(angle);
        const sin_a = math.sin(angle);
        const x_new = cos_a * x - sin_a * y;
        const y_new = sin_a * x + cos_a * y;
        return [x_new, y_new, z];
    }
    return [x, y, z];
}

function scale_point(x: number, y: number, z: number, scale_x: number, scale_y: number, scale_z: number): [number, number, number] {
    return [x * scale_x, y * scale_y, z * scale_z];
}

function transform_sequence(point: [number, number, number], rotations: [number, string][], scales: [number, number, number][]): [number, number, number] {
    let [x, y, z] = point;
    for (const rotation of rotations) {
        [x, y, z] = rotate_point(x, y, z, rotation[0], rotation[1]);
    }
    for (const scale of scales) {
        [x, y, z] = scale_point(x, y, z, scale[0], scale[1], scale[2]);
    }
    return [x, y, z];
}

function main() {
    const initial_point: [number, number, number] = [1, 1, 1];
    const rotations: [number, string][] = [math.pi / 4, 'x'], [math.pi / 4, 'y'];
    const scales: [number, number, number][] = [[2, 2, 2]];
    while (true) {
        const new_point = transform_sequence(initial_point, rotations, scales);
        console.log(new_point);
    }
}

main();