function transform_coordinates(x: number, y: number, z: number, a: number, b: number, c: number): [number, number, number] {
    let x_new = x + a;
    let y_new = y + b;
    let z_new = z + c;
    return [x_new, y_new, z_new];
}

let x = 1.0, y = 2.0, z = 3.0, a = 4.0, b = 5.0, c = 6.0;
let [x_new, y_new, z_new] = transform_coordinates(x, y, z, a, b, c);
console.log(`Transformed coordinates: (${x_new}, ${y_new}, ${z_new})`);