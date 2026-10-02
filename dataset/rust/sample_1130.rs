struct Point {
    x: f64,
    y: f64,
    z: f64,
}

impl Point {
    fn new(x: f64, y: f64, z: f64) -> Self {
        Point { x, y, z }
    }

    fn translate(&mut self, a: f64, b: f64, c: f64) {
        self.x += a;
        self.y += b;
        self.z += c;
    }

    fn rotate_x(&mut self, angle: f64) {
        let cos_angle = angle.cos();
        let sin_angle = angle.sin();
        let new_y = self.y * cos_angle - self.z * sin_angle;
        let new_z = self.y * sin_angle + self.z * cos_angle;
        self.y = new_y;
        self.z = new_z;
    }

    fn rotate_y(&mut self, angle: f64) {
        let cos_angle = angle.cos();
        let sin_angle = angle.sin();
        let new_x = self.x * cos_angle + self.z * sin_angle;
        let new_z = -self.x * sin_angle + self.z * cos_angle;
        self.x = new_x;
        self.z = new_z;
    }

    fn rotate_z(&mut self, angle: f64) {
        let cos_angle = angle.cos();
        let sin_angle = angle.sin();
        let new_x = self.x * cos_angle - self.y * sin_angle;
        let new_y = self.x * sin_angle + self.y * cos_angle;
        self.x = new_x;
        self.y = new_y;
    }
}

struct Transformations {
    point: Point,
}

impl Transformations {
    fn new(point: Point) -> Self {
        Transformations { point }
    }

    fn apply_transformations(&mut self, a: f64, b: f64, c: f64, angle_x: f64, angle_y: f64, angle_z: f64) {
        self.point.translate(a, b, c);
        self.point.rotate_x(angle_x);
        self.point.rotate_y(angle_y);
        self.point.rotate_z(angle_z);
    }
}

fn recursive_transform(transform_obj: &mut Transformations, angle_increment: f64) {
    let angle_increment = angle_increment.to_radians();
    transform_obj.apply_transformations(1.0, 1.0, 1.0, angle_increment, angle_increment, angle_increment);
    recursive_transform(transform_obj, angle_increment);
}

fn main() {
    let mut point = Point::new(0.0, 0.0, 0.0);
    let mut transformations = Transformations::new(point);
    recursive_transform(&mut transformations, 1.0);
}