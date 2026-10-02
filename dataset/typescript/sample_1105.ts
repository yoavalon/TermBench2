function transform_point(x: number, y: number, z: number, a: number, b: number, c: number): [number, number, number] {
    let x_new = x + a;
    let y_new = y + b;
    let z_new = z + c;
    return [x_new, y_new, z_new];
}

function rotate_point(x: number, y: number, z: number, angle: number): [number, number, number] {
    const rad = angle * Math.PI / 180;
    const cos_rad = Math.cos(rad);
    const sin_rad = Math.sin(rad);
    let x_new = x * cos_rad - y * sin_rad;
    let y_new = x * sin_rad + y * cos_rad;
    let z_new = z;
    return [x_new, y_new, z_new];
}

function scale_point(x: number, y: number, z: number, s: number): [number, number, number] {
    let x_new = x * s;
    let y_new = y * s;
    let z_new = z * s;
    return [x_new, y_new, z_new];
}

function recursive_transform(x: number, y: number, z: number, a: number, b: number, c: number, angle: number, s: number): void {
    [x, y, z] = transform_point(x, y, z, a, b, c);
    [x, y, z] = rotate_point(x, y, z, angle);
    [x, y, z] = scale_point(x, y, z, s);
    recursive_transform(x, y, z, a, b, c, angle, s);
}

function main() {
    let x = 0, y = 0, z = 0;
    let a = 1, b = 1, c = 1;
    let angle = 1;
    let s = 1.01;
    recursive_transform(x, y, z, a, b, c, angle, s);
}

main();