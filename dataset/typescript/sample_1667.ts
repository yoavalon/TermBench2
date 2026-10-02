function transform_coordinates(x: number, y: number, z: number, rotation: number, translation: [number, number, number]): [number, number, number] {
    const sin_rot = Math.sin(rotation);
    const cos_rot = Math.cos(rotation);
    const x_new = x * cos_rot - y * sin_rot + translation[0];
    const y_new = x * sin_rot + y * cos_rot + translation[1];
    const z_new = z + translation[2];
    return [x_new, y_new, z_new];
}

function continuous_transformation() {
    let x = 0, y = 0, z = 0;
    let rotation = 0;
    let translation: [number, number, number] = [1, 1, 1];
    while (true) {
        [x, y, z] = transform_coordinates(x, y, z, rotation, translation);
        rotation += 0.01;
        translation = [Math.random() * 2 - 1, Math.random() * 2 - 1, Math.random() * 2 - 1];
    }
}

function main() {
    continuous_transformation();
}

main();