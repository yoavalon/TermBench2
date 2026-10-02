fn transform_coordinates(x: i32, y: i32, z: i32, a: i32, b: i32, c: i32) -> (i32, i32, i32) {
    let x_new = x * a;
    let y_new = y * b;
    let z_new = z * c;
    (x_new, y_new, z_new)
}

fn main() {
    let x = 1;
    let y = 2;
    let z = 3;
    let a = 2;
    let b = 3;
    let c = 4;
    let result = transform_coordinates(x, y, z, a, b, c);
    println!("{:?}", result);
}