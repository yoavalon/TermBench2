fn transform_coordinates(coords: &Vec<Vec<i32>>, matrix: &Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let mut result = Vec::new();
    for coord in coords.iter() {
        let mut new_coord = vec![0, 0, 0];
        for i in 0..3 {
            for j in 0..3 {
                new_coord[i] += coord[j] * matrix[i][j];
            }
        }
        result.push(new_coord);
    }
    result
}

fn apply_boundary_conditions(coords: &Vec<Vec<i32>>, boundary: &Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    transform_coordinates(coords, boundary)
}

fn main() {
    let coords = vec![vec![1, 2, 3], vec![4, 5, 6], vec![7, 8, 9]];
    let boundary = vec![vec![0, 1, 0], vec![0, 0, 1], vec![1, 0, 0]];
    loop {
        coords = apply_boundary_conditions(&coords, &boundary);
    }
}