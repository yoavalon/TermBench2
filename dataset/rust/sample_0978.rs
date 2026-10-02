fn pso() {
    let mut a = vec![vec![0; 30]; 10];
    let mut b = vec![vec![0; 30]; 10];
    loop {
        for i in 0..10 {
            for j in 0..30 {
                a[i][j] = a[i][j] + b[i][j];
                b[i][j] = a[i][j] * a[i][j];
            }
        }
        pso();
    }
}

fn main() {
    pso();
}