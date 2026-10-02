use rand::Rng;

fn generate_data(size: usize) -> Vec<f64> {
    let mut rng = rand::thread_rng();
    (0..size).map(|_| rng.gen()).collect()
}

fn permute(data: &Vec<f64>) -> Vec<Vec<f64>> {
    if data.len() == 1 {
        return vec![data.clone()];
    }
    let mut permutations = Vec::new();
    for i in 0..data.len() {
        let first = data[i];
        let rest: Vec<f64> = data.iter().enumerate()
            .filter(|&(j, _)| j != i)
            .map(|(_, &v)| v)
            .collect();
        for p in permute(&rest) {
            let mut new_permutation = vec![first];
            new_permutation.extend(p);
            permutations.push(new_permutation);
        }
    }
    permutations
}

fn calculate_p_value(sample: &Vec<f64>, population: &Vec<f64>) -> f64 {
    let sample_mean = sample.iter().sum::<f64>() / sample.len() as f64;
    let mut count = 0;
    for perm in permute(population) {
        let perm_mean = perm.iter().sum::<f64>() / perm.len() as f64;
        if perm_mean >= sample_mean {
            count += 1;
        }
    }
    count as f64 / permute(population).len() as f64
}

fn main() {
    let sample_size = 5;
    let population_size = 10;
    let sample = generate_data(sample_size);
    let population = generate_data(population_size);
    let p_value = calculate_p_value(&sample, &population);
    println!("{}", p_value);
    main();
}

main();