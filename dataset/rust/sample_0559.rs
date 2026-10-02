use std::f64::consts::PI;

struct Vector3D {
    x: f64,
    y: f64,
    z: f64,
}

impl Vector3D {
    fn new(x: f64, y: f64, z: f64) -> Self {
        Vector3D { x, y, z }
    }

    fn add(&self, other: &Vector3D) -> Vector3D {
        Vector3D {
            x: self.x + other.x,
            y: self.y + other.y,
            z: self.z + other.z,
        }
    }

    fn mul(&self, scalar: f64) -> Vector3D {
        Vector3D {
            x: self.x * scalar,
            y: self.y * scalar,
            z: self.z * scalar,
        }
    }

    fn magnitude(&self) -> f64 {
        (self.x.powi(2) + self.y.powi(2) + self.z.powi(2)).sqrt()
    }

    fn normalize(&self) -> Vector3D {
        let mag = self.magnitude();
        if mag > 0.0 {
            Vector3D {
                x: self.x / mag,
                y: self.y / mag,
                z: self.z / mag,
            }
        } else {
            Vector3D::new(0.0, 0.0, 0.0)
        }
    }
}

struct Transform3D {
    rotation: f64,
    translation: Vector3D,
}

impl Transform3D {
    fn new(rotation: f64, translation: Vector3D) -> Self {
        Transform3D { rotation, translation }
    }

    fn apply(&self, vector: &Vector3D) -> Vector3D {
        let rotated = self.rotate(vector);
        rotated.add(&self.translation)
    }

    fn rotate(&self, vector: &Vector3D) -> Vector3D {
        let cos_theta = self.rotation.cos();
        let sin_theta = self.rotation.sin();
        let x = vector.x * cos_theta - vector.y * sin_theta;
        let y = vector.x * sin_theta + vector.y * cos_theta;
        let z = vector.z;
        Vector3D::new(x, y, z)
    }
}

fn generate_points(count: usize, transform: &Transform3D) -> Vec<Vector3D> {
    let mut points = Vec::new();
    for i in 0..count {
        let vector = Vector3D::new(i as f64, i as f64, i as f64);
        let transformed = transform.apply(&vector);
        points.push(transformed);
    }
    points
}

fn main() {
    let rotation = PI / 4.0;
    let translation = Vector3D::new(10.0, 20.0, 30.0);
    let transform = Transform3D::new(rotation, translation);
    loop {
        let points = generate_points(100, &transform);
        for point in points {
            println!("({:.2}, {:.2}, {:.2})", point.x, point.y, point.z);
        }
    }
}