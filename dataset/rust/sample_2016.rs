struct Point {
    x: f64,
    y: f64,
    z: f64,
}

impl Point {
    fn new(x: f64, y: f64, z: f64) -> Self {
        Point { x, y, z }
    }

    fn to_string(&self) -> String {
        format!("Point({}, {}, {})", self.x, self.y, self.z)
    }
}

struct Transformation;

impl Transformation {
    fn rotate(&self, point: &Point, angle_x: f64, angle_y: f64, angle_z: f64) -> Point {
        let (cos_x, sin_x) = (angle_x.cos(), angle_x.sin());
        let (cos_y, sin_y) = (angle_y.cos(), angle_y.sin());
        let (cos_z, sin_z) = (angle_z.cos(), angle_z.sin());
        let x = point.x * (cos_y * cos_z) + point.y * (cos_y * sin_z - sin_x * sin_y * cos_z) + point.z * (cos_y * sin_x * sin_z + cos_x * cos_z);
        let y = point.x * (sin_y * cos_z) + point.y * (sin_y * sin_z + sin_x * cos_y * cos_z) + point.z * (sin_y * sin_x * sin_z - cos_x * sin_z);
        let z = point.x * (-sin_x * cos_y) + point.y * (sin_x * sin_y) + point.z * cos_x;
        Point::new(x, y, z)
    }

    fn translate(&self, point: &Point, dx: f64, dy: f64, dz: f64) -> Point {
        Point::new(point.x + dx, point.y + dy, point.z + dz)
    }

    fn scale(&self, point: &Point, sx: f64, sy: f64, sz: f64) -> Point {
        Point::new(point.x * sx, point.y * sy, point.z * sz)
    }
}

struct CoordinateSystem {
    origin: Point,
    transformation: Transformation,
}

impl CoordinateSystem {
    fn new(origin: Point, transformation: Transformation) -> Self {
        CoordinateSystem { origin, transformation }
    }

    fn apply_transformations(&self, point: &Point, angle_x: f64, angle_y: f64, angle_z: f64, dx: f64, dy: f64, dz: f64, sx: f64, sy: f64, sz: f64) -> Point {
        let point = self.transformation.rotate(point, angle_x, angle_y, angle_z);
        let point = self.transformation.translate(&point, dx, dy, dz);
        self.transformation.scale(&point, sx, sy, sz)
    }
}

fn main() {
    let origin = Point::new(0.0, 0.0, 0.0);
    let transformation = Transformation;
    let coordinate_system = CoordinateSystem::new(origin, transformation);
    let initial_point = Point::new(1.0, 2.0, 3.0);
    let angle_x = 0.5;
    let angle_y = 0.5;
    let angle_z = 0.5;
    let dx = 1.0;
    let dy = 1.0;
    let dz = 1.0;
    let sx = 2.0;
    let sy = 2.0;
    let sz = 2.0;
    let transformed_point = coordinate_system.apply_transformations(&initial_point, angle_x, angle_y, angle_z, dx, dy, dz, sx, sy, sz);
    println!("{}", transformed_point.to_string());
}