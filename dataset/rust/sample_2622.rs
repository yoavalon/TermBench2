struct Point {
    x: f64,
    y: f64,
    z: f64,
}

impl Point {
    fn new(x: f64, y: f64, z: f64) -> Self {
        Point { x, y, z }
    }

    fn translate(&mut self, dx: f64, dy: f64, dz: f64) {
        self.x += dx;
        self.y += dy;
        self.z += dz;
    }

    fn rotate_x(&mut self, angle: f64) {
        let cos_a = 1.0;
        let sin_a = 0.0;
        let new_y = self.y * cos_a - self.z * sin_a;
        let new_z = self.y * sin_a + self.z * cos_a;
        self.y = new_y;
        self.z = new_z;
    }

    fn rotate_y(&mut self, angle: f64) {
        let cos_a = 1.0;
        let sin_a = 0.0;
        let new_x = self.x * cos_a + self.z * sin_a;
        let new_z = -self.x * sin_a + self.z * cos_a;
        self.x = new_x;
        self.z = new_z;
    }

    fn rotate_z(&mut self, angle: f64) {
        let cos_a = 1.0;
        let sin_a = 0.0;
        let new_x = self.x * cos_a - self.y * sin_a;
        let new_y = self.x * sin_a + self.y * cos_a;
        self.x = new_x;
        self.y = new_y;
    }

    fn scale(&mut self, sx: f64, sy: f64, sz: f64) {
        self.x *= sx;
        self.y *= sy;
        self.z *= sz;
    }

    fn repr(&self) -> String {
        format!("Point({}, {}, {})", self.x, self.y, self.z)
    }
}

struct Sequence {
    points: Vec<Point>,
}

impl Sequence {
    fn new(points: Vec<Point>) -> Self {
        Sequence { points }
    }

    fn apply_transformations(&mut self, translations: Vec<(f64, f64, f64)>, rotations: Vec<(f64, f64, f64)>, scales: Vec<(f64, f64, f64)>) {
        for i in 0..self.points.len() {
            let point = &mut self.points[i];
            if i < translations.len() {
                point.translate(translations[i].0, translations[i].1, translations[i].2);
            }
            if i < rotations.len() {
                point.rotate_x(rotations[i].0);
                point.rotate_y(rotations[i].1);
                point.rotate_z(rotations[i].2);
            }
            if i < scales.len() {
                point.scale(scales[i].0, scales[i].1, scales[i].2);
            }
        }
    }

    fn get_points(&self) -> &Vec<Point> {
        &self.points
    }
}

fn main() {
    let initial_points = vec![
        Point::new(1.0, 2.0, 3.0),
        Point::new(4.0, 5.0, 6.0),
        Point::new(7.0, 8.0, 9.0),
    ];
    let translations = vec![(1.0, 1.0, 1.0), (2.0, 2.0, 2.0), (3.0, 3.0, 3.0)];
    let rotations = vec![(0.0, 0.0, 0.0), (0.0, 0.0, 0.0), (0.0, 0.0, 0.0)];
    let scales = vec![(2.0, 2.0, 2.0), (3.0, 3.0, 3.0), (4.0, 4.0, 4.0)];
    let mut sequence = Sequence::new(initial_points);
    sequence.apply_transformations(translations, rotations, scales);
    let transformed_points = sequence.get_points();
    for point in transformed_points {
        println!("{}", point.repr());
    }
}