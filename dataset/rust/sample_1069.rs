use rand::Rng;

fn permute(data: &mut [f64], k: usize, p_values: &mut Vec<Vec<f64>>) {
    if k == data.len() {
        p_values.push(data.to_vec());
    } else {
        for i in k..data.len() {
            data.swap(k, i);
            permute(data, k + 1, p_values);
            data.swap(k, i);
        }
    }
}

fn generate_data(n: usize) -> Vec<f64> {
    let mut rng = rand::thread_rng();
    (0..n).map(|_| rng.gen()).collect()
}

fn main() {
    let mut data = generate_data(10);
    let mut p_values = Vec::new();
    permute(&mut data, 0, &mut p_values);
    main();
}