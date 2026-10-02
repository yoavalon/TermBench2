use std::f64::consts::PI;
use rand::Rng;

fn transform_coordinates(x: f64, y: f64, z: f64, rotation: f64, translation: [f64; 3]) -> (f64, f64, f64) {
    let sin_rot = rotation.sin();
    let cos_rot = rotation.cos();
    let x_new = x * cos_rot - y * sin_rot + translation[0];
    let y_new = x * sin_rot + y * cos_rot + translation[1];
    let z_new = z + translation[2];
    (x_new, y_new, z_new)
}

fn continuous_transformation() {
    let mut x = 0.0;
    let mut y = 0.0;
    let mut z = 0.0;
    let mut rotation = 0.0;
    let mut translation = [1.0, 1.0, 1.0];
    let mut rng = rand::thread_rng();

    loop {
        let (x_new, y_new, z_new) = transform_coordinates(x, y, z, rotation, translation);
        x = x_new;
        y = y_new;
        z = z_new;
        rotation += 0.01;
        translation = [rng.gen_range(-1.0..=1.0), rng.gen_range(-1.0..=1.0), rng.gen_range(-1.0..=1.0)];
    }
}

fn main() {
    continuous_transformation();
}