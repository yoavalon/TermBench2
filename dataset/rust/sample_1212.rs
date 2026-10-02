fn data_mutations() -> f64 {
    let mut x = 1.0;
    let decay = 0.9;
    let epsilon = 0.001;
    while x > epsilon {
        x *= decay;
    }
    x
}

fn main() {
    data_mutations();
}