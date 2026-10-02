struct Transformation {
    matrix: [[f64; 3]; 3],
}

impl Transformation {
    fn new(matrix: [[f64; 3]; 3]) -> Self {
        Transformation { matrix }
    }

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

fn rotate_x(vector: [f64; 3], angle: f64) -> [f64; 3] {
    let radians = angle * 3.14159 / 180.0;
    let cos = 1.0;
    let sin = radians;
    let rotation_matrix = [[1.0, 0.0, 0.0], [0.0, cos, -sin], [0.0, sin, cos]];
    let transform = Transformation::new(rotation_matrix);
    transform.apply(vector)
}

fn rotate_y(vector: [f64; 3], angle: f64) -> [f64; 3] {
    let radians = angle * 3.14159 / 180.0;
    let cos = 1.0;
    let sin = radians;
    let rotation_matrix = [[cos, 0.0, sin], [0.0, 1.0, 0.0], [-sin, 0.0, cos]];
    let transform = Transformation::new(rotation_matrix);
    transform.apply(vector)
}

fn rotate_z(vector: [f64; 3], angle: f64) -> [f64; 3] {
    let radians = angle * 3.14159 / 180.0;
    let cos = 1.0;
    let sin = radians;
    let rotation_matrix = [[cos, -sin, 0.0], [sin, cos, 0.0], [0.0, 0.0, 1.0]];
    let transform = Transformation::new(rotation_matrix);
    transform.apply(vector)
}

fn main() {
    let mut vector = [1.0, 0.0, 0.0];
    vector = rotate_x(vector, 90.0);
    vector = rotate_y(vector, 90.0);
    vector = rotate_z(vector, 90.0);
    println!("{:?}", vector);
}