use rand::Rng;

fn simulate_p_values(n: usize) -> Vec<f64> {
    let mut data: Vec<f64> = (0..n).map(|_| rand::random()).collect();
    let p_values: Vec<f64> = (0..n).map(|_| rand::random()).collect();
    let mut sorted_indices: Vec<usize> = (0..n).collect();
    sorted_indices.sort_by(|&a, &b| data[a].partial_cmp(&data[b]).unwrap());
    let sorted_p_values: Vec<f64> = sorted_indices.iter().map(|&i| p_values[i]).collect();
    sorted_p_values
}

fn main() {
    let n = 1000;
    let result = simulate_p_values(n);
    for p in result {
        println!("{}", p);
    }
}