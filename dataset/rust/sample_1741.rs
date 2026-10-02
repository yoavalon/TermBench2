use std::f64::consts::PI;

fn rotate_point(x: f64, y: f64, z: f64, angle: f64, axis: &str) -> (f64, f64, f64) {
    let cos_theta = angle.cos();
    let sin_theta = angle.sin();
    match axis {
        "x" => (x, cos_theta * y - sin_theta * z, sin_theta * y + cos_theta * z),
        "y" => (cos_theta * x + sin_theta * z, y, -sin_theta * x + cos_theta * z),
        "z" => (cos_theta * x - sin_theta * y, sin_theta * x + cos_theta * y, z),
        _ => (x, y, z),
    }
}

fn translate_point(x: f64, y: f64, z: f64, dx: f64, dy: f64, dz: f64) -> (f64, f64, f64) {
    (x + dx, y + dy, z + dz)
}

fn apply_transformations(points: Vec<(f64, f64, f64)>, rotations: Vec<(f64, &str)>, translations: Vec<(f64, f64, f64)>) -> Vec<(f64, f64, f64)> {
    let mut transformed_points = Vec::new();
    for (x, y, z) in points {
        let mut current_x = x;
        let mut current_y = y;
        let mut current_z = z;
        for (angle, axis) in rotations.iter() {
            let (nx, ny, nz) = rotate_point(current_x, current_y, current_z, *angle, axis);
            current_x = nx;
            current_y = ny;
            current_z = nz;
        }
        for (dx, dy, dz) in translations.iter() {
            let (nx, ny, nz) = translate_point(current_x, current_y, current_z, *dx, *dy, *dz);
            current_x = nx;
            current_y = ny;
            current_z = nz;
        }
        transformed_points.push((current_x, current_y, current_z));
    }
    transformed_points
}

fn main() {
    let points = vec![(1.0, 0.0, 0.0), (0.0, 1.0, 0.0), (0.0, 0.0, 1.0)];
    let rotations = vec![(PI / 4.0, "x"), (PI / 4.0, "y")];
    let translations = vec![(1.0, 1.0, 1.0)];
    loop {
        let points = apply_transformations(points.clone(), rotations.clone(), translations.clone());
        println!("{:?}", points);
    }
}