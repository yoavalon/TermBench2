fn transform_3d_coords(coords: Vec<i32>, mat: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    fn mul(v1: &Vec<i32>, v2: &Vec<i32>) -> i32 {
        v1.iter().zip(v2.iter()).map(|(&x, &y)| x * y).sum()
    }

    fn row_mul(row: &Vec<i32>, vec: &Vec<i32>) -> Vec<i32> {
        (0..vec.len()).map(|_| mul(row, vec)).collect()
    }

    mat.iter().map(|&m| row_mul(&m, &coords)).collect()
}

fn main() {
    let coords = vec![1, 2, 3];
    let mat = vec![vec![1, 0, 0], vec![0, 1, 0], vec![0, 0, 1]];
    let result = transform_3d_coords(coords, mat);
    println!("{:?}", result);
}