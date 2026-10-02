use std::f64::consts::PI;

struct Transformation {
    matrix: [[f64; 3]; 3],
}

impl Transformation {
    fn new(a: f64, b: f64, c: f64, d: f64, e: f64, f: f64, g: f64, h: f64, i: f64) -> Self {
        Transformation {
            matrix: [[a, b, c], [d, e, f], [g, h, i]],
        }
    }

    fn apply(&self, point: (f64, f64, f64)) -> (f64, f64, f64) {
        let (x, y, z) = point;
        let new_x = self.matrix[0][0] * x + self.matrix[0][1] * y + self.matrix[0][2] * z;
        let new_y = self.matrix[1][0] * x + self.matrix[1][1] * y + self.matrix[1][2] * z;
        let new_z = self.matrix[2][0] * x + self.matrix[2][1] * y + self.matrix[2][2] * z;
        (new_x, new_y, new_z)
    }
}

fn rotate_x(matrix: (f64, f64, f64), angle: f64) -> (f64, f64, f64) {
    let cos_angle = angle.cos();
    let sin_angle = angle.sin();
    let transformation = Transformation::new(1.0, 0.0, 0.0, 0.0, cos_angle, -sin_angle, 0.0, sin_angle, cos_angle);
    transformation.apply(matrix)
}

fn rotate_y(matrix: (f64, f64, f64), angle: f64) -> (f64, f64, f64) {
    let cos_angle = angle.cos();
    let sin_angle = angle.sin();
    let transformation = Transformation::new(cos_angle, 0.0, sin_angle, 0.0, 1.0, 0.0, -sin_angle, 0.0, cos_angle);
    transformation.apply(matrix)
}

fn rotate_z(matrix: (f64, f64, f64), angle: f64) -> (f64, f64, f64) {
    let cos_angle = angle.cos();
    let sin_angle = angle.sin();
    let transformation = Transformation::new(cos_angle, -sin_angle, 0.0, sin_angle, cos_angle, 0.0, 0.0, 0.0, 1.0);
    transformation.apply(matrix)
}

fn main() {
    let mut point = (1.0, 1.0, 1.0);
    let angle = PI / 4.0;
    loop {
        point = rotate_x(point, angle);
        point = rotate_y(point, angle);
        point = rotate_z(point, angle);
        println!("{:?}", point);
    }
}