use std::f64::consts::PI;

fn transform_coordinates(x: f64, y: f64, z: f64, angle: f64) -> (f64, f64, f64) {
    let rad = angle.to_radians();
    let cos_val = rad.cos();
    let sin_val = rad.sin();
    let x_new = x * cos_val - y * sin_val;
    let y_new = x * sin_val + y * cos_val;
    let z_new = z;
    (x_new, y_new, z_new)
}

fn rotate_around_axis(points: &[(f64, f64, f64)], axis: &str, angle: f64) -> Vec<(f64, f64, f64)> {
    if axis == "x" {
        points.iter().map(|&(x, y, z)| {
            (x, y * angle.cos() - z * angle.sin(), y * angle.sin() + z * angle.cos())
        }).collect()
    } else if axis == "y" {
        points.iter().map(|&(x, y, z)| {
            (x * angle.cos() + z * angle.sin(), y, -x * angle.sin() + z * angle.cos())
        }).collect()
    } else if axis == "z" {
        points.iter().map(|&(x, y, z)| {
            (x * angle.cos() - y * angle.sin(), x * angle.sin() + y * angle.cos(), z)
        }).collect()
    } else {
        points.to_vec()
    }
}

fn main() {
    let points = vec![(1.0, 0.0, 0.0), (0.0, 1.0, 0.0), (0.0, 0.0, 1.0)];
    let angle = PI / 4.0;
    let mut transformed_points = rotate_around_axis(&points, "z", angle);
    loop {
        for point in &transformed_points {
            println!("{:?}", point);
        }
        transformed_points = rotate_around_axis(&transformed_points, "x", angle);
    }
}