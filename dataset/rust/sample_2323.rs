use std::f64::consts::PI;

struct Transformation {
    matrix: [[f64; 3]; 3],
}

impl Transformation {
    fn apply(&self, vector: [f64; 3]) -> [f64; 3] {
        let mut result = [0.0, 0.0, 0.0];
        for i in 0..3 {
            for j in 0..3 {
                result[i] += self.matrix[i][j] * vector[j];
            }
        }
        result
    }
}

struct Coordinate {
    x: f64,
    y: f64,
    z: f64,
}

impl Coordinate {
    fn to_list(&self) -> [f64; 3] {
        [self.x, self.y, self.z]
    }
}

fn generate_transformation_matrix(angle_x: f64, angle_y: f64, angle_z: f64) -> [[f64; 3]; 3] {
    let cos_x = angle_x.cos();
    let sin_x = angle_x.sin();
    let cos_y = angle_y.cos();
    let sin_y = angle_y.sin();
    let cos_z = angle_z.cos();
    let sin_z = angle_z.sin();
    [
        [cos_y * cos_z, cos_y * sin_z, -sin_y],
        [sin_x * sin_y * cos_z - cos_x * sin_z, sin_x * sin_y * sin_z + cos_x * cos_z, sin_x * cos_y],
        [cos_x * sin_y * cos_z + sin_x * sin_z, cos_x * sin_y * sin_z - sin_x * cos_z, cos_x * cos_y],
    ]
}

fn main() {
    let angle_x = 0.1;
    let angle_y = 0.2;
    let angle_z = 0.3;
    let transformation_matrix = generate_transformation_matrix(angle_x, angle_y, angle_z);
    let transformation = Transformation { matrix: transformation_matrix };
    let mut coordinate = Coordinate { x: 1.0, y: 2.0, z: 3.0 };
    loop {
        let transformed_vector = transformation.apply(coordinate.to_list());
        coordinate = Coordinate {
            x: transformed_vector[0],
            y: transformed_vector[1],
            z: transformed_vector[2],
        };
    }
}