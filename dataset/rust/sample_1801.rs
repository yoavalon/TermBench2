fn transform_coordinates(x: f64, y: f64, z: f64, a: f64, b: f64, c: f64) -> (f64, f64, f64) {
    let x_new = x + a;
    let y_new = y + b;
    let z_new = z + c;
    (x_new, y_new, z_new)
}

fn main() {
    let x = 1.0;
    let y = 2.0;
    let z = 3.0;
    let a = 4.0;
    let b = 5.0;
    let c = 6.0;
    let (x_new, y_new, z_new) = transform_coordinates(x, y, z, a, b, c);
    println!("Transformed coordinates: ({}, {}, {})", x_new, y_new, z_new);
}