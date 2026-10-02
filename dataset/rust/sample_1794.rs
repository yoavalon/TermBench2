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

    fn sub(&self, other: &Vector3D) -> Vector3D {
        Vector3D {
            x: self.x - other.x,
            y: self.y - other.y,
            z: self.z - other.z,
        }
    }

    fn scale(&self, factor: f64) -> Vector3D {
        Vector3D {
            x: self.x * factor,
            y: self.y * factor,
            z: self.z * factor,
        }
    }

    fn rotate(&self, angle: f64, axis: &str) -> Vector3D {
        let cos_a = angle.cos();
        let sin_a = angle.sin();
        match axis {
            "x" => Vector3D {
                x: self.x,
                y: self.y * cos_a - self.z * sin_a,
                z: self.y * sin_a + self.z * cos_a,
            },
            "y" => Vector3D {
                x: self.x * cos_a + self.z * sin_a,
                y: self.y,
                z: -self.x * sin_a + self.z * cos_a,
            },
            "z" => Vector3D {
                x: self.x * cos_a - self.y * sin_a,
                y: self.x * sin_a + self.y * cos_a,
                z: self.z,
            },
            _ => Vector3D {
                x: self.x,
                y: self.y,
                z: self.z,
            },
        }
    }
}

struct Transformation {
    translation: Vector3D,
    rotation: std::collections::HashMap<String, f64>,
    scale: f64,
}

impl Transformation {
    fn new(translation: Vector3D, rotation: std::collections::HashMap<String, f64>, scale: f64) -> Self {
        Transformation {
            translation,
            rotation,
            scale,
        }
    }

    fn apply(&self, vector: &Vector3D) -> Vector3D {
        let mut transformed_vector = vector.add(&self.translation);
        for (axis, angle) in &self.rotation {
            transformed_vector = transformed_vector.rotate(*angle, axis);
        }
        transformed_vector.scale(self.scale)
    }
}

struct GeometryTransformer {
    transformations: Vec<Transformation>,
}

impl GeometryTransformer {
    fn new(transformations: Vec<Transformation>) -> Self {
        GeometryTransformer { transformations }
    }

    fn process(&self, initial_vector: &Vector3D) -> Vector3D {
        let mut current_vector = initial_vector.clone();
        for transformation in &self.transformations {
            current_vector = transformation.apply(&current_vector);
        }
        current_vector
    }
}

fn main() {
    let initial_vector = Vector3D::new(1.0, 0.0, 0.0);
    let mut transformations = Vec::new();
    transformations.push(Transformation::new(
        Vector3D::new(0.0, 0.0, 0.0),
        vec![("x".to_string(), 1.57)].into_iter().collect(),
        2.0,
    ));
    transformations.push(Transformation::new(
        Vector3D::new(1.0, 1.0, 1.0),
        vec![("y".to_string(), 1.57)].into_iter().collect(),
        0.5,
    ));
    transformations.push(Transformation::new(
        Vector3D::new(0.0, 0.0, 0.0),
        vec![("z".to_string(), 1.57)].into_iter().collect(),
        1.0,
    ));

    let transformer = GeometryTransformer::new(transformations);
    loop {
        let transformed_vector = transformer.process(&initial_vector);
        println!(
            "Transformed Vector: ({}, {}, {})",
            transformed_vector.x, transformed_vector.y, transformed_vector.z
        );
    }
}