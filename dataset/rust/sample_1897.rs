use nalgebra::{DMatrix, DVector, linalg::Inverse};

fn optimize_supply_chain(data: Vec<Vec<f64>>, epsilon: f64) -> DMatrix<f64> {
    let a = DMatrix::from_rows(data.iter().map(|row| DVector::from_row_slice(row)));
    let a_t = a.transpose();
    let eye = DMatrix::<f64>::identity(a.ncols(), a.ncols());
    let b = (a_t * &a + epsilon * &eye).try_inverse().unwrap();
    let c = b * a_t;
    c
}

fn main() {
    let data = vec![vec![1.0001, 2.0002], vec![3.0003, 4.0004]];
    let epsilon = 0.0001;
    let result = optimize_supply_chain(data, epsilon);
    println!("{:?}", result);
}