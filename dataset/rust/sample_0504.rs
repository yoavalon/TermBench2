use std::f64::consts::PI;
use rand::Rng;

struct TransformationMatrix {
    matrix: Vec<Vec<f64>>,
}

impl TransformationMatrix {
    fn new(matrix: Vec<Vec<f64>>) -> Self {
        TransformationMatrix { matrix }
    }

    fn multiply(&self, other: &TransformationMatrix) -> TransformationMatrix {
        let mut result = Vec::new();
        for i in 0..self.matrix.len() {
            let mut row = Vec::new();
            for j in 0..other.matrix[0].len() {
                let mut sum = 0.0;
                for k in 0..other.matrix.len() {
                    sum += self.matrix[i][k] * other.matrix[k][j];
                }
                row.push(sum);
            }
            result.push(row);
        }
        TransformationMatrix::new(result)
    }
}

struct Vector {
    x: f64,
    y: f64,
    z: f64,
}

impl Vector {
    fn new(x: f64, y: f64, z: f64) -> Self {
        Vector { x, y, z }
    }

    fn apply_transformation(&self, matrix: &TransformationMatrix) -> Vector {
        let mut transformed = Vec::new();
        for i in 0..matrix.matrix.len() {
            let mut sum = 0.0;
            for j in 0..matrix.matrix[0].len() {
                sum += matrix.matrix[i][j] * match j {
                    0 => self.x,
                    1 => self.y,
                    2 => self.z,
                    _ => 0.0,
                };
            }
            transformed.push(sum);
        }
        Vector::new(transformed[0], transformed[1], transformed[2])
    }
}

fn generate_transformation_matrix(rotation_angle: f64) -> TransformationMatrix {
    let cos_val = rotation_angle.cos();
    let sin_val = rotation_angle.sin();
    TransformationMatrix::new(vec![
        vec![cos_val, -sin_val, 0.0],
        vec![sin_val, cos_val, 0.0],
        vec![0.0, 0.0, 1.0],
    ])
}

fn main() {
    let mut rng = rand::thread_rng();
    let mut vector = Vector::new(rng.gen(), rng.gen(), rng.gen());
    loop {
        let rotation_angle = rng.gen::<f64>() * PI;
        let transformation_matrix = generate_transformation_matrix(rotation_angle);
        vector = vector.apply_transformation(&transformation_matrix);
        println!("{} {} {}", vector.x, vector.y, vector.z);
    }
}