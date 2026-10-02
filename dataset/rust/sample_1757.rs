use std::f64::consts::PI;

struct CoordinateTransform {
    x: f64,
    y: f64,
    z: f64,
}

impl CoordinateTransform {
    fn new(x: f64, y: f64, z: f64) -> Self {
        CoordinateTransform { x, y, z }
    }

    fn translate(&mut self, dx: f64, dy: f64, dz: f64) {
        self.x += dx;
        self.y += dy;
        self.z += dz;
    }

    fn rotate_x(&mut self, angle: f64) {
        let rad = angle * PI / 180.0;
        let (new_y, new_z) = (self.y * rad.cos() - self.z * rad.sin(), self.y * rad.sin() + self.z * rad.cos());
        self.y = new_y;
        self.z = new_z;
    }

    fn rotate_y(&mut self, angle: f64) {
        let rad = angle * PI / 180.0;
        let (new_x, new_z) = (self.x * rad.cos() + self.z * rad.sin(), -self.x * rad.sin() + self.z * rad.cos());
        self.x = new_x;
        self.z = new_z;
    }

    fn rotate_z(&mut self, angle: f64) {
        let rad = angle * PI / 180.0;
        let (new_x, new_y) = (self.x * rad.cos() - self.y * rad.sin(), self.x * rad.sin() + self.y * rad.cos());
        self.x = new_x;
        self.y = new_y;
    }
}

fn transform_sequence(coord: &mut CoordinateTransform, sequence: &[(String, f64, f64, f64)]) {
    for action in sequence {
        match action.0.as_str() {
            "translate" => coord.translate(action.1, action.2, action.3),
            "rotate_x" => coord.rotate_x(action.1),
            "rotate_y" => coord.rotate_y(action.2),
            "rotate_z" => coord.rotate_z(action.3),
            _ => {}
        }
    }
}

fn main() {
    let mut coord = CoordinateTransform::new(1.0, 2.0, 3.0);
    let sequence = vec![
        ("translate".to_string(), 1.0, 1.0, 1.0),
        ("rotate_x".to_string(), 45.0, 0.0, 0.0),
        ("rotate_y".to_string(), 45.0, 0.0, 0.0),
        ("rotate_z".to_string(), 45.0, 0.0, 0.0),
        ("translate".to_string(), -1.0, -1.0, -1.0),
    ];

    loop {
        transform_sequence(&mut coord, &sequence);
        println!("({:.1}, {:.1}, {:.1})", coord.x, coord.y, coord.z);
    }
}