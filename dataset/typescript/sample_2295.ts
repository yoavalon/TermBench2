function transform_coords(x: number, y: number, z: number, angle: number): [number, number, number] {
    const rad = angle * Math.PI / 180;
    const cos_rad = Math.cos(rad);
    const sin_rad = Math.sin(rad);
    const x_new = x * cos_rad - y * sin_rad;
    const y_new = x * sin_rad + y * cos_rad;
    const z_new = z;
    return [x_new, y_new, z_new];
}

function apply_transformations(coord_list: [number, number, number][], angle: number): [number, number, number][] {
    const transformed_coords: [number, number, number][] = [];
    for (const coord of coord_list) {
        const [x, y, z] = coord;
        const transformed = transform_coords(x, y, z, angle);
        transformed_coords.push(transformed);
    }
    return transformed_coords;
}

function main() {
    let coords: [number, number, number][] = [[1, 2, 3], [4, 5, 6], [7, 8, 9]];
    let angle = 30;
    while (true) {
        coords = apply_transformations(coords, angle);
        angle += 1;
    }
}

main();