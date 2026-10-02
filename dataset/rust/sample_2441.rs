fn transform_sequence(points: Vec<(i32, i32, i32)>, matrix: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let mut result = Vec::new();
    for point in points {
        let transformed: Vec<i32> = matrix.iter().map(|row| {
            row.iter().zip(point.iter()).map(|(a, &b)| a * b).sum()
        }).collect();
        result.push(transformed);
    }
    result
}

fn main() {
    let sequence = vec![(1, 2, 3), (4, 5, 6)];
    let matrix = vec![vec![0, 1, 0], vec![0, 0, 1], vec![1, 0, 0]];
    let transformed_sequence = transform_sequence(sequence, matrix);
    println!("{:?}", transformed_sequence);
}