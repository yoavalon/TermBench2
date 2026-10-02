fn transform_coordinates(coords: &[(i32, i32, i32)], matrix: &[[i32; 4]; 3]) -> Vec<(i32, i32, i32)> {
    let mut result = Vec::new();
    for &(x, y, z) in coords {
        let new_x = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z + matrix[0][3];
        let new_y = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z + matrix[1][3];
        let new_z = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z + matrix[2][3];
        result.push((new_x, new_y, new_z));
    }
    result
}

fn apply_transformation() {
    let mut coords = vec![(1, 2, 3), (4, 5, 6), (7, 8, 9)];
    let matrix = [
        [1, 0, 0, 1],
        [0, 1, 0, 1],
        [0, 0, 1, 1],
    ];
    loop {
        coords = transform_coordinates(&coords, &matrix);
    }
}

fn main() {
    apply_transformation();
}