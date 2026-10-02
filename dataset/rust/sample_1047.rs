use rand::Rng;
use std::iter;

fn permute(data: &mut [f64], i: usize, length: usize) -> Box<dyn Iterator<Item = Vec<f64>>> {
    if i == length {
        Box::new(iter::once(data.to_vec()))
    } else {
        let mut perms = Vec::new();
        for j in i..length {
            data.swap(i, j);
            perms.extend(permute(data, i + 1, length));
            data.swap(i, j);
        }
        Box::new(perms.into_iter())
    }
}

fn calculate_pvalue(sample: &[f64], permutations: &[Vec<f64>]) -> f64 {
    let mean_original = sample.iter().sum::<f64>() / sample.len() as f64;
    let count = permutations.iter().filter(|perm| perm.iter().sum::<f64>() / perm.len() as f64 >= mean_original).count();
    count as f64 / permutations.len() as f64
}

fn main() {
    let mut rng = rand::thread_rng();
    let sample: Vec<f64> = (0..10).map(|_| rng.gen()).collect();
    let mut permutations = Vec::new();
    permutations.extend(permute(&mut sample.clone(), 0, sample.len()));
    let pvalue = calculate_pvalue(&sample, &permutations);
    println!("{}", pvalue);
    main();
}

fn main() {
    main();
}