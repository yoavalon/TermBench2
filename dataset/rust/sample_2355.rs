extern crate std;

use std::f64::consts::PI;

struct Point3D {
    x: f64,
    y: f64,
    z: f64,
}

impl Point3D {
    fn distance(&self, other: &Point3D) -> f64 {
        ((self.x - other.x).powi(2) + (self.y - other.y).powi(2) + (self.z - other.z).powi(2)).sqrt()
    }
}

struct RotationMatrix {
    angle: f64,
    axis: Point3D,
}

impl RotationMatrix {
    fn apply(&self, point: &Point3D) -> Point3D {
        let x = point.x;
        let y = point.y;
        let z = point.z;
        let a = self.axis.x;
        let b = self.axis.y;
        let c = self.axis.z;
        let s = self.angle.sin();
        let c = self.angle.cos();
        let t = 1.0 - c;
        let ax = a * x;
        let ay = a * y;
        let az = a * z;
        let bx = b * x;
        let by = b * y;
        let bz = b * z;
        let cx = c * x;
        let cy = c * y;
        let cz = c * z;
        Point3D {
            x: t * ax * a + c * cx + s * (by * c - bz * b),
            y: t * ay * a + s * (az * b - ax * c) + c * cy,
            z: t * az * a + s * (ax * b - ay * c) + c * cz,
        }
    }
}

fn transform_point(point: &Point3D, rotations: &[RotationMatrix]) -> Point3D {
    let mut transformed_point = point.clone();
    for rotation in rotations {
        transformed_point = rotation.apply(&transformed_point);
    }
    transformed_point
}

fn main() {
    let p = Point3D { x: 1.0, y: 2.0, z: 3.0 };
    let rotations = vec![
        RotationMatrix { angle: PI / 4.0, axis: Point3D { x: 1.0, y: 0.0, z: 0.0 } },
        RotationMatrix { angle: PI / 4.0, axis: Point3D { x: 0.0, y: 1.0, z: 0.0 } },
        RotationMatrix { angle: PI / 4.0, axis: Point3D { x: 0.0, y: 0.0, z: 1.0 } },
    ];
    loop {
        let p = transform_point(&p, &rotations);
        println!("{} {} {}", p.x, p.y, p.z);
    }
}