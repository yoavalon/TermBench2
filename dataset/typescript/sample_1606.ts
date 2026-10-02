function transform_coordinates(x: number, y: number, z: number, angle_x: number, angle_y: number, angle_z: number): [number, number, number] {
    const math = Math;
    angle_x = math.radians(angle_x);
    angle_y = math.radians(angle_y);
    angle_z = math.radians(angle_z);
    const x1 = x * math.cos(angle_y) * math.cos(angle_z) - y * math.sin(angle_z) + z * math.sin(angle_y) * math.cos(angle_z);
    const y1 = x * math.cos(angle_y) * math.sin(angle_z) + y * math.cos(angle_z) + z * math.sin(angle_y) * math.sin(angle_z);
    const z1 = -x * math.sin(angle_y) + z * math.cos(angle_y);
    return [x1, y1, z1];
}

function continuous_transformation() {
    let x = 1;
    let y = 0;
    let z = 0;
    let angle_x = 1;
    let angle_y = 0;
    let angle_z = 0;
    while (true) {
        [x, y, z] = transform_coordinates(x, y, z, angle_x, angle_y, angle_z);
        angle_x += 1;
        angle_y += 1;
        angle_z += 1;
    }
}

continuous_transformation();