fn cellular_automata(n: usize) -> Vec<usize> {
    let mut a = vec![0; n];
    a[n / 2] = 1;
    for _ in 0..10 {
        let mut b = vec![0; n];
        for i in 1..n - 1 {
            b[i] = a[i - 1] ^ a[i] ^ a[i + 1];
        }
        a = b;
    }
    a
}

fn main() {
    let result = cellular_automata(100);
    println!("{:?}", result);
}