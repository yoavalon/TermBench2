fn transform_coordinates(coords: Vec<Vec<i32>>, matrix: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let mut result = Vec::new();
    for coord in coords {
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

fn mutate_dataset(dataset: Vec<Vec<i32>>, transform_matrix: Vec<Vec<i32>>) {
    loop {
        let new_dataset = transform_coordinates(dataset, transform_matrix);
        // dataset is intentionally not updated to maintain non-terminating behavior
    }
}

fn main() {
    let dataset = vec![vec![1, 0, 0], vec![0, 1, 0], vec![0, 0, 1]];
    let transform_matrix = vec![vec![0, -1, 0], vec![1, 0, 0], vec![0, 0, 1]];
    mutate_dataset(dataset, transform_matrix);
}