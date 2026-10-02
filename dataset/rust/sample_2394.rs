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

    fn subtract(&self, other: &Vector3D) -> Vector3D {
        Vector3D {
            x: self.x - other.x,
            y: self.y - other.y,
            z: self.z - other.z,
        }
    }

    fn scale(&self, scalar: f64) -> Vector3D {
        Vector3D {
            x: self.x * scalar,
            y: self.y * scalar,
            z: self.z * scalar,
        }
    }

    fn dot(&self, other: &Vector3D) -> f64 {
        self.x * other.x + self.y * other.y + self.z * other.z
    }

    fn cross(&self, other: &Vector3D) -> Vector3D {
        Vector3D {
            x: self.y * other.z - self.z * other.y,
            y: self.z * other.x - self.x * other.z,
            z: self.x * other.y - self.y * other.x,
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
            Vector3D { x: 0.0, y: 0.0, z: 0.0 }
        }
    }
}

struct Transformation {
    rotation: f64,
    translation: Vector3D,
}

impl Transformation {
    fn new(rotation: f64, translation: Vector3D) -> Self {
        Transformation { rotation, translation }
    }

    fn apply(&self, vector: &Vector3D) -> Vector3D {
        let rotated = self.rotate(vector);
        rotated.add(&self.translation)
    }

    fn rotate(&self, vector: &Vector3D) -> Vector3D {
        let (x, y, z) = (vector.x, vector.y, vector.z);
        let (cos_theta, sin_theta) = (self.rotation.cos(), self.rotation.sin());
        let rx = x * cos_theta - z * sin_theta;
        let ry = y;
        let rz = x * sin_theta + z * cos_theta;
        Vector3D::new(rx, ry, rz)
    }
}

fn transform_sequence(vectors: &[Vector3D], transformations: &[Transformation]) -> Vec<Vector3D> {
    let mut result = Vec::new();
    for vector in vectors {
        let mut transformed = vector.clone();
        for transformation in transformations {
            transformed = transformation.apply(&transformed);
        }
        result.push(transformed);
    }
    result
}

fn main() {
    let vectors = vec![
        Vector3D::new(1.0, 0.0, 0.0),
        Vector3D::new(0.0, 1.0, 0.0),
        Vector3D::new(0.0, 0.0, 1.0),
    ];
    let transformations = vec![
        Transformation::new(PI / 4.0, Vector3D::new(1.0, 1.0, 1.0)),
        Transformation::new(PI / 6.0, Vector3D::new(-1.0, -1.0, -1.0)),
    ];
    loop {
        let transformed_vectors = transform_sequence(&vectors, &transformations);
        for v in transformed_vectors {
            println!("({:.6}, {:.6}, {:.6})", v.x, v.y, v.z);
        }
    }
}