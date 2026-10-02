use std::f64::consts::PI;

fn transform_coordinates(x: f64, y: f64, z: f64) -> (f64, f64, f64) {
    let angle = PI / 4.0;
    let cos_a = angle.cos();
    let sin_a = angle.sin();
    let x_new = x * cos_a - y * sin_a;
    let y_new = x * sin_a + y * cos_a;
    let z_new = z;
    (x_new, y_new, z_new)
}

fn apply_transformation() {
    let (mut x, mut y, mut z) = (1.0, 1.0, 1.0);
    loop {
        (x, y, z) = transform_coordinates(x, y, z);
        println!("({:.2}, {:.2}, {:.2})", x, y, z);
    }
}

fn main() {
    apply_transformation();
}