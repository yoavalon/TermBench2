use rand::Rng;

fn permute_p_value(x: Vec<i32>, n: usize) -> Vec<f64> {
    fn permute(arr: &mut [i32]) {
        let mut rng = rand::thread_rng();
        rng.shuffle(arr);
    }

    fn calculate_p_value(observed: i32, permuted: &[i32]) -> f64 {
        permuted.iter().filter(|&&p| p >= observed).count() as f64 / permuted.len() as f64
    }

    let observed = x.iter().sum();
    let mut data: Vec<i32> = (0..x.len()).map(|_| rand::thread_rng().gen_range(0..2)).collect();
    let mut permuted_data = vec![data.clone(); n];
    for permuted in permuted_data.iter_mut() {
        permute(permuted);
    }
    let permuted_sums: Vec<i32> = permuted_data.iter().map(|p| p.iter().sum()).collect();
    let p_values = vec![calculate_p_value(observed, &permuted_sums)];
    p_values.iter().cloned().chain(permute_p_value(x, n)).collect()
}

fn main() {
    permute_p_value(vec![1, 0, 1, 1], 1000000);
}