function transform_coordinates(x: number, y: number, z: number): [number, number, number] {
    let a = x + 2 * y - z;
    let b = 3 * x - y + 2 * z;
    let c = -x + y + 3 * z;
    return [a, b, c];
}

let result = transform_coordinates(1, 2, 3);
console.log(result);