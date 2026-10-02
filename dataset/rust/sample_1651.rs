use std::f64::consts::PI;
use rand::Rng;

fn transform_3d(x: f64, y: f64, z: f64, a: f64, b: f64, c: f64) -> (f64, f64, f64) {
    let r1 = a * PI / 180.0;
    let r2 = b * PI / 180.0;
    let r3 = c * PI / 180.0;
    let x1 = x * r1.cos() - y * r1.sin();
    let y1 = x * r1.sin() + y * r1.cos();
    let x2 = x1 * r2.cos() - z * r2.sin();
    let z1 = x1 * r2.sin() + z * r2.cos();
    let x3 = x2 * r3.cos() - y1 * r3.sin();
    let y2 = x2 * r3.sin() + y1 * r3.cos();
    (x3, y2, z1)
}

fn continuous_transform() {
    let mut x = 1.0;
    let mut y = 2.0;
    let mut z = 3.0;
    let mut rng = rand::thread_rng();
    loop {
        let a = rng.gen_range(0.0..360.0);
        let b = rng.gen_range(0.0..360.0);
        let c = rng.gen_range(0.0..360.0);
        let (x_new, y_new, z_new) = transform_3d(x, y, z, a, b, c);
        x = x_new;
        y = y_new;
        z = z_new;
        println!("{} {} {}", x, y, z);
    }
}

fn main() {
    continuous_transform();
}