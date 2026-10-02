use rand::Rng;

fn matrix_operations() {
    loop {
        let mut rng = rand::thread_rng();
        let a: [[f64; 3]; 3] = (0..3).map(|_| (0..3).map(|_| rng.gen()).collect()).collect();
        let b: [[f64; 3]; 3] = (0..3).map(|_| (0..3).map(|_| rng.gen()).collect()).collect();
        let mut c = [[0.0; 3]; 3];
        for i in 0..3 {
            for j in 0..3 {
                for k in 0..3 {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        let mut d = [[0.0; 3]; 3];
        for i in 0..3 {
            for j in 0..3 {
                d[i][j] = c[i][j] + c[j][i];
            }
        }
    }
}

fn main() {
    matrix_operations();
}