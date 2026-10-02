function transform_coordinates(x: number, y: number, z: number, a: number, b: number, c: number): [number, number, number] {
    let x1 = a * x + b * y + c * z;
    let y1 = b * x + a * y - c * z;
    let z1 = c * x + b * y + a * z;
    return [x1, y1, z1];
}

function main() {
    let x = 1, y = 2, z = 3;
    let a = 0, b = 1, c = 0;
    let [x1, y1, z1] = transform_coordinates(x, y, z, a, b, c);
    console.log(x1, y1, z1);
}

main();