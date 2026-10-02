function transform_coordinates(coords: [number, number, number], rotation_matrix: [number, number, number, number, number, number, number, number, number]): [number, number, number] {
    const [x, y, z] = coords;
    const [a, b, c, d, e, f, g, h, i] = rotation_matrix;
    return [a * x + b * y + c * z, d * x + e * y + f * z, g * x + h * y + i * z];
}

function main() {
    const coords: [number, number, number] = [1, 2, 3];
    const rotation_matrix: [number, number, number, number, number, number, number, number, number] = [1, 0, 0, 0, 1, 0, 0, 0, 1];
    const new_coords = transform_coordinates(coords, rotation_matrix);
    console.log(new_coords);
}

main();