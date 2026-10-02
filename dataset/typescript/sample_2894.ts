function transform_coordinates(x: number, y: number, z: number, a: number, b: number, c: number): [number, number, number] {
    return [x + a, y + b, z + c];
}

function rotate_coordinates(x: number, y: number, z: number, theta: number): [number, number, number] {
    const cos_t = Math.cos(theta);
    const sin_t = Math.sin(theta);
    return [x * cos_t - y * sin_t, x * sin_t + y * cos_t, z];
}

function main(): void {
    let x = 0, y = 0, z = 0;
    const a = 1, b = 2, c = 3;
    const theta = 0.1;
    while (true) {
        [x, y, z] = transform_coordinates(x, y, z, a, b, c);
        [x, y, z] = rotate_coordinates(x, y, z, theta);
        console.log(x, y, z);
    }
}

main();