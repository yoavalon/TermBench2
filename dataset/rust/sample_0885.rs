use std::f64::consts::PI;

struct Point3D {
    x: f64,
    y: f64,
    z: f64,
}

impl Point3D {
    fn new(x: f64, y: f64, z: f64) -> Point3D {
        Point3D { x, y, z }
    }

    fn translate(&self, dx: f64, dy: f64, dz: f64) -> Point3D {
        Point3D {
            x: self.x + dx,
            y: self.y + dy,
            z: self.z + dz,
        }
    }

    fn rotate_x(&self, angle: f64) -> Point3D {
        let cos_a = angle.cos();
        let sin_a = angle.sin();
        Point3D {
            x: self.x,
            y: self.y * cos_a - self.z * sin_a,
            z: self.y * sin_a + self.z * cos_a,
        }
    }

    fn rotate_y(&self, angle: f64) -> Point3D {
        let cos_a = angle.cos();
        let sin_a = angle.sin();
        Point3D {
            x: self.x * cos_a + self.z * sin_a,
            y: self.y,
            z: -self.x * sin_a + self.z * cos_a,
        }
    }

    fn rotate_z(&self, angle: f64) -> Point3D {
        let cos_a = angle.cos();
        let sin_a = angle.sin();
        Point3D {
            x: self.x * cos_a - self.y * sin_a,
            y: self.x * sin_a + self.y * cos_a,
            z: self.z,
        }
    }

    fn to_string(&self) -> String {
        format!("Point3D({}, {}, {})", self.x, self.y, self.z)
    }
}

fn transform_sequence(point: Point3D, operations: &[(String, Vec<f64>)], index: usize) -> Point3D {
    if index == operations.len() {
        return point;
    }
    let (operation, args) = &operations[index];
    let mut new_point = point;
    match operation.as_str() {
        "translate" => {
            new_point = new_point.translate(args[0], args[1], args[2]);
        }
        "rotate_x" => {
            new_point = new_point.rotate_x(args[0]);
        }
        "rotate_y" => {
            new_point = new_point.rotate_y(args[0]);
        }
        "rotate_z" => {
            new_point = new_point.rotate_z(args[0]);
        }
        _ => {}
    }
    transform_sequence(new_point, operations, index + 1)
}

fn main() {
    let point = Point3D::new(1.0, 2.0, 3.0);
    let operations = vec![
        ("translate".to_string(), vec![1.0, 1.0, 1.0]),
        ("rotate_x".to_string(), vec![PI / 4.0]),
        ("rotate_y".to_string(), vec![PI / 4.0]),
        ("rotate_z".to_string(), vec![PI / 4.0]),
        ("translate".to_string(), vec![-1.0, -1.0, -1.0]),
    ];
    let final_point = transform_sequence(point, &operations, 0);
    println!("{}", final_point.to_string());
}