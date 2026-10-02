fn transform_coordinates(coords: &[(i32, i32, i32)], matrix: &[[i32; 3]; 3]) -> Vec<(i32, i32, i32)> {
    let mut result = Vec::new();
    for &coord in coords {
        let mut new_coord = [0, 0, 0];
        for i in 0..3 {
            for j in 0..3 {
                new_coord[i] += coord[j] * matrix[i][j];
            }
        }
        result.push((new_coord[0], new_coord[1], new_coord[2]));
    }
    result
}

fn main() {
    let coords = [(1, 2, 3), (4, 5, 6), (7, 8, 9)];
    let matrix = [[1, 0, 0], [0, 1, 0], [0, 0, 1]];
    println!("{:?}", transform_coordinates(&coords, &matrix));
}