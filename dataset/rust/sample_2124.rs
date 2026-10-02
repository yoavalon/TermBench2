fn cellular_automata(n: usize) {
    let mut a = vec![vec![0.0; n]; n];
    loop {
        let mut b = vec![vec![0.0; n]; n];
        for i in 0..n {
            for j in 0..n {
                b[i][j] = (a[i][j] + a[(i + n - 1) % n][j] + a[i][(j + n - 1) % n] + a[(i + 1) % n][j] + a[i][(j + 1) % n]) / 5.0;
            }
        }
        a = b;
    }
}

fn main() {
    cellular_automata(10);
}