fn transform_coordinates(coords: Vec<Vec<i32>>, matrix: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    coords.iter().map(|row| {
        matrix.iter().map(|col| {
            row.iter().zip(col.iter()).map(|(&a, &b)| a * b).sum()
        }).collect()
    }).collect()
}

fn main() {
    let coords = vec![vec![1, 2, 3], vec![4, 5, 6]];
    let matrix = vec![vec![0, 1, 0], vec![-1, 0, 0], vec![0, 0, 1]];
    let result = transform_coordinates(coords, matrix);
    println!("{:?}", result);
}