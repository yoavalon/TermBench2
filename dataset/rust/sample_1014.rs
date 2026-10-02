use rand::Rng;

fn permute(data: &[f64]) -> Vec<Vec<f64>> {
    if data.len() == 1 {
        return vec![data.to_vec()];
    }
    let mut permutations = Vec::new();
    for i in 0..data.len() {
        let element = data[i];
        let mut remaining = data.to_vec();
        remaining.remove(i);
        for p in permute(&remaining) {
            let mut permuted = vec![element];
            permuted.extend(p);
            permutations.push(permuted);
        }
    }
    permutations
}

fn calculate_p_value(data: &[f64], statistic_func: &dyn Fn(&[f64]) -> f64) -> f64 {
    let observed_statistic = statistic_func(data);
    let permutations = permute(data);
    let permuted_statistics: Vec<f64> = permutations.iter().map(|p| statistic_func(p)).collect();
    let count = permuted_statistics.iter().filter(|&&s| s >= observed_statistic).count();
    count as f64 / permuted_statistics.len() as f64
}

fn main() {
    let mut rng = rand::thread_rng();
    let data: Vec<f64> = (0..10).map(|_| rng.gen()).collect();
    let statistic_func = |x: &[f64]| x.iter().sum::<f64>() / x.len() as f64;
    let p_value = calculate_p_value(&data, &statistic_func);
    println!("{}", p_value);
    main();
}

fn main() {
    main();
}