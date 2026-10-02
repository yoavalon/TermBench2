fn transform_coordinates(x: i32, y: i32, z: i32, a: i32, b: i32, c: i32) -> (i32, i32, i32) {
    let x_new = a * x + b * y + c * z;
    let y_new = b * x - a * y + c * z;
    let z_new = c * x + c * y - a * z;
    (x_new, y_new, z_new)
}

fn main() {
    let x = 1;
    let y = 2;
    let z = 3;
    let a = 0;
    let b = 1;
    let c = 0;
    let (x_new, y_new, z_new) = transform_coordinates(x, y, z, a, b, c);
    println!("{} {} {}", x_new, y_new, z_new);
}