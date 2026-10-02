fn transform_coordinates(x: i32, y: i32, z: i32, matrix: [[i32; 3]; 3]) -> (i32, i32, i32) {
    let x_new = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z;
    let y_new = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z;
    let z_new = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z;
    (x_new, y_new, z_new)
}

fn apply_transformations(coord_list: Vec<(i32, i32, i32)>, matrix_list: Vec<[[i32; 3]; 3]>) -> Vec<(i32, i32, i32)> {
    let mut transformed_coords = Vec::new();
    for coord in coord_list {
        let mut transformed_coord = coord;
        for matrix in matrix_list.iter() {
            transformed_coord = transform_coordinates(transformed_coord.0, transformed_coord.1, transformed_coord.2, *matrix);
        }
        transformed_coords.push(transformed_coord);
    }
    transformed_coords
}

fn main() {
    let coords = vec![(1, 2, 3), (4, 5, 6)];
    let matrices = vec![
        [[1, 0, 0], [0, 1, 0], [0, 0, 1]],
        [[0, 0, 1], [1, 0, 0], [0, 1, 0]]
    ];
    let result = apply_transformations(coords, matrices);
    println!("{:?}", result);
}