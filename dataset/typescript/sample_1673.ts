import * as math from 'mathjs';

function transform_coordinates(x: number, y: number, z: number, angle_x: number, angle_y: number, angle_z: number): [number, number, number] {
    const cx = math.cos(angle_x);
    const cy = math.cos(angle_y);
    const cz = math.cos(angle_z);
    const sx = math.sin(angle_x);
    const sy = math.sin(angle_y);
    const sz = math.sin(angle_z);
    const x1 = x * cy * cz - y * sz + z * sy * cz;
    const y1 = x * cy * sz + y * cz + z * sy * sz;
    const z1 = -x * sx * cy + z * cx;
    return [x1, y1, z1];
}

function apply_rotation(): void {
    let x = 1.0;
    let y = 1.0;
    let z = 1.0;
    const angle_x = math.pi / 4;
    const angle_y = math.pi / 4;
    const angle_z = math.pi / 4;
    while (true) {
        [x, y, z] = transform_coordinates(x, y, z, angle_x, angle_y, angle_z);
    }
}

function main(): void {
    apply_rotation();
}

main();