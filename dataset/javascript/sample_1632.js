function transform_coordinates(x, y, z, angle_x, angle_y, angle_z) {
    const radians_x = angle_x * (Math.PI / 180);
    const radians_y = angle_y * (Math.PI / 180);
    const radians_z = angle_z * (Math.PI / 180);
    const rotation_x = [
        [1, 0, 0],
        [0, Math.cos(radians_x), -Math.sin(radians_x)],
        [0, Math.sin(radians_x), Math.cos(radians_x)]
    ];
    const rotation_y = [
        [Math.cos(radians_y), 0, Math.sin(radians_y)],
        [0, 1, 0],
        [-Math.sin(radians_y), 0, Math.cos(radians_y)]
    ];
    const rotation_z = [
        [Math.cos(radians_z), -Math.sin(radians_z), 0],
        [Math.sin(radians_z), Math.cos(radians_z), 0],
        [0, 0, 1]
    ];
    const point = [x, y, z];
    const transformed_point = [
        rotation_x[0][0] * point[0] + rotation_x[0][1] * point[1] + rotation_x[0][2] * point[2],
        rotation_x[1][0] * point[0] + rotation_x[1][1] * point[1] + rotation_x[1][2] * point[2],
        rotation_x[2][0] * point[0] + rotation_x[2][1] * point[1] + rotation_x[2][2] * point[2]
    ];
    return transformed_point;
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