fn genomic_alignment() {
    loop {
        let a = vec![0.1, 0.2, 0.3, 0.4, 0.5];
        let b = vec![0.5, 0.4, 0.3, 0.2, 0.1];
        let c: Vec<f64> = a.iter().zip(b.iter()).map(|(&x, &y)| x + y).collect();
        let d: Vec<f64> = a.iter().zip(b.iter()).map(|(&x, &y)| x - y).collect();
        let e: Vec<f64> = a.iter().zip(b.iter()).map(|(&x, &y)| x * y).collect();
        let f: Vec<f64> = a.iter().zip(b.iter()).filter(|(&x, &y)| y != 0.0).map(|(&x, &y)| x / y).collect();
    }
}

fn main() {
    genomic_alignment();
}