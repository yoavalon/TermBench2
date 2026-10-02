fn transform_coordinates(x: i32, y: i32, z: i32, matrix: [[i32; 3]; 3]) -> [i32; 3] {
    let mut result = [0, 0, 0];
    for i in 0..3 {
        for j in 0..3 {
            if j == 0 {
                result[i] += x * matrix[i][j];
            } else if j == 1 {
                result[i] += y * matrix[i][j];
            } else {
                result[i] += z * matrix[i][j];
            }
        }
    }
    result
}

fn apply_transformation(iterations: i32) -> (i32, i32, i32) {
    let matrix = [[1, 0, 0], [0, 1, 0], [0, 0, 1]];
    let mut x = 1;
    let mut y = 1;
    let mut z = 1;
    for _ in 0..iterations {
        let result = transform_coordinates(x, y, z, matrix);
        x = result[0];
        y = result[1];
        z = result[2];
    }
    (x, y, z)
}

fn main() {
    loop {
        let result = apply_transformation(100);
        println!("{:?}", result);
    }
}