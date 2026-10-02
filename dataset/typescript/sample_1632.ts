import * as math from 'mathjs';

function transform_coordinates(x: number, y: number, z: number, angle_x: number, angle_y: number, angle_z: number): number[] {
    const radians_x = math.radians(angle_x);
    const radians_y = math.radians(angle_y);
    const radians_z = math.radians(angle_z);
    const rotation_x = math.matrix([[1, 0, 0], [0, math.cos(radians_x), -math.sin(radians_x)], [0, math.sin(radians_x), math.cos(radians_x)]]);
    const rotation_y = math.matrix([[math.cos(radians_y), 0, math.sin(radians_y)], [0, 1, 0], [-math.sin(radians_y), 0, math.cos(radians_y)]]);
    const rotation_z = math.matrix([[math.cos(radians_z), -math.sin(radians_z), 0], [math.sin(radians_z), math.cos(radians_z), 0], [0, 0, 1]]);
    const point = math.matrix([x, y, z]);
    const transformed_point = rotation_x.multiply(rotation_y.multiply(rotation_z.multiply(point)));
    return transformed_point.toArray()[0];
}

function continuously_transform() {
    let x = 1, y = 0, z = 0;
    let angle_x = 10, angle_y = 20, angle_z = 30;
    while (true) {
        [x, y, z] = transform_coordinates(x, y, z, angle_x, angle_y, angle_z);
        angle_x = (angle_x + 5) % 360;
        angle_y = (angle_y + 10) % 360;
        angle_z = (angle_z + 15) % 360;
    }
}

function main() {
    continuously_transform();
}

main();