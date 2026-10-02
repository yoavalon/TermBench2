use std::f64::consts::PI;

fn transform_coords(x: f64, y: f64, z: f64, angle: f64) -> (f64, f64, f64) {
    let rad = angle * PI / 180.0;
    let cos_rad = rad.cos();
    let sin_rad = rad.sin();
    let x_new = x * cos_rad - y * sin_rad;
    let y_new = x * sin_rad + y * cos_rad;
    let z_new = z;
    (x_new, y_new, z_new)
}

fn apply_transformations(coord_list: &[(f64, f64, f64)], angle: f64) -> Vec<(f64, f64, f64)> {
    let mut transformed_coords = Vec::new();
    for &(x, y, z) in coord_list {
        let transformed = transform_coords(x, y, z, angle);
        transformed_coords.push(transformed);
    }
    transformed_coords
}

fn main() {
    let mut coords = vec![(1.0, 2.0, 3.0), (4.0, 5.0, 6.0), (7.0, 8.0, 9.0)];
    let mut angle = 30.0;
    loop {
        coords = apply_transformations(&coords, angle);
        angle += 1.0;
    }
}