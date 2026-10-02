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

    fn scale(&self, sx: f64, sy: f64, sz: f64) -> Point3D {
        Point3D {
            x: self.x * sx,
            y: self.y * sy,
            z: self.z * sz,
        }
    }

    fn rotate_x(&self, angle: f64) -> Point3D {
        let c = angle.cos();
        let s = angle.sin();
        Point3D {
            x: self.x,
            y: self.y * c - self.z * s,
            z: self.y * s + self.z * c,
        }
    }

    fn rotate_y(&self, angle: f64) -> Point3D {
        let c = angle.cos();
        let s = angle.sin();
        Point3D {
            x: self.x * c + self.z * s,
            y: self.y,
            z: -self.x * s + self.z * c,
        }
    }

    fn rotate_z(&self, angle: f64) -> Point3D {
        let c = angle.cos();
        let s = angle.sin();
        Point3D {
            x: self.x * c - self.y * s,
            y: self.x * s + self.y * c,
            z: self.z,
        }
    }
}

struct Transformation {
    point: Point3D,
}

impl Transformation {
    fn new(point: Point3D) -> Transformation {
        Transformation { point }
    }

    fn apply_transformations(&mut self, translations: &[(f64, f64, f64)], scalings: &[(f64, f64, f64)], rotations: &[f64]) {
        for &(dx, dy, dz) in translations {
            self.point = self.point.translate(dx, dy, dz);
        }
        for &(sx, sy, sz) in scalings {
            self.point = self.point.scale(sx, sy, sz);
        }
        for &angle in rotations {
            self.point = self.point.rotate_x(angle);
            self.point = self.point.rotate_y(angle);
            self.point = self.point.rotate_z(angle);
        }
    }

    fn get_final_position(&self) -> (f64, f64, f64) {
        (self.point.x, self.point.y, self.point.z)
    }
}

fn main() {
    let initial_point = Point3D::new(1.0, 2.0, 3.0);
    let mut transformations = Transformation::new(initial_point);
    let translations = [(1.0, 0.0, 0.0), (0.0, 1.0, 0.0)];
    let scalings = [(2.0, 2.0, 2.0)];
    let rotations = [PI / 4.0];
    transformations.apply_transformations(&translations, &scalings, &rotations);
    let final_position = transformations.get_final_position();
    println!("{:?}", final_position);
}