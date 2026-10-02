import * as math from 'mathjs';

function rotate_point(x: number, y: number, z: number, angle_x: number, angle_y: number, angle_z: number): [number, number, number] {
    let rad_x = math.radians(angle_x);
    let rad_y = math.radians(angle_y);
    let rad_z = math.radians(angle_z);
    let cos_x = math.cos(rad_x);
    let sin_x = math.sin(rad_x);
    let cos_y = math.cos(rad_y);
    let sin_y = math.sin(rad_y);
    let cos_z = math.cos(rad_z);
    let sin_z = math.sin(rad_z);
    let x_new = x * (cos_y * cos_z) + y * (cos_x * sin_z - sin_x * sin_y * cos_z) + z * (cos_x * cos_y * sin_z + sin_x * sin_y);
    let y_new = x * (cos_y * sin_z) + y * (cos_x * cos_z + sin_x * sin_y * sin_z) + z * (cos_x * cos_y * cos_z - sin_x * sin_y);
    let z_new = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y;
    return [x_new, y_new, z_new];
}

function scale_point(x: number, y: number, z: number, scale: number): [number, number, number] {
    return [x * scale, y * scale, z * scale];
}

function main() {
    let point = [1, 1, 1];
    let angles = [45, 30, 60];
    let scale = 2;
    let [x, y, z] = rotate_point(point[0], point[1], point[2], angles[0], angles[1], angles[2]);
    [x, y, z] = scale_point(x, y, z, scale);
    console.log(`Transformed Point: (${x}, ${y}, ${z})`);
}

main();