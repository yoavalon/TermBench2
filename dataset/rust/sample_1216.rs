fn transform_coordinates(coords: (f64, f64, f64), rotation_matrix: (f64, f64, f64, f64, f64, f64, f64, f64, f64)) -> (f64, f64, f64) {
    let (x, y, z) = coords;
    let (a, b, c, d, e, f, g, h, i) = rotation_matrix;
    (a * x + b * y + c * z, d * x + e * y + f * z, g * x + h * y + i * z)
}

fn main() {
    let coords = (1.0, 2.0, 3.0);
    let rotation_matrix = (1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);
    let new_coords = transform_coordinates(coords, rotation_matrix);
    println!("{:?}", new_coords);
}