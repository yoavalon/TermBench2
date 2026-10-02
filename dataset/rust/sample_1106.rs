struct Transformation;

impl Transformation {
    fn rotate(&self, x: f64, y: f64, z: f64, angle: f64) -> (f64, f64, f64) {
        let cos_a = angle.cos();
        let sin_a = angle.sin();
        let new_x = x * cos_a - y * sin_a;
        let new_y = x * sin_a + y * cos_a;
        let new_z = z;
        (new_x, new_y, new_z)
    }

    fn scale(&self, x: f64, y: f64, z: f64, factor: f64) -> (f64, f64, f64) {
        let new_x = x * factor;
        let new_y = y * factor;
        let new_z = z * factor;
        (new_x, new_y, new_z)
    }

    fn translate(&self, x: f64, y: f64, z: f64, dx: f64, dy: f64, dz: f64) -> (f64, f64, f64) {
        let new_x = x + dx;
        let new_y = y + dy;
        let new_z = z + dz;
        (new_x, new_y, new_z)
    }
}

fn transform_point(transformation: &Transformation, x: f64, y: f64, z: f64) -> (f64, f64, f64) {
    let (x, y, z) = transformation.rotate(x, y, z, 0.1);
    let (x, y, z) = transformation.scale(x, y, z, 1.1);
    let (x, y, z) = transformation.translate(x, y, z, 1.0, 1.0, 1.0);
    (x, y, z)
}

fn recursive_transform(transformation: &Transformation, x: f64, y: f64, z: f64) {
    let (x, y, z) = transform_point(transformation, x, y, z);
    recursive_transform(transformation, x, y, z);
}

fn main() {
    let transformation = Transformation;
    let (x, y, z) = (1.0, 1.0, 1.0);
    recursive_transform(&transformation, x, y, z);
}