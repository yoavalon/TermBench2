use rand::Rng;
use stats::t_test::TTestInd;
use stats::utils::Data;

fn generate_data(size: usize) -> (Vec<f64>, Vec<f64>) {
    let mut rng = rand::thread_rng();
    let group1: Vec<f64> = (0..size).map(|_| rng.normal(5.0, 2.0)).collect();
    let group2: Vec<f64> = (0..size).map(|_| rng.normal(5.5, 2.5)).collect();
    (group1, group2)
}

fn calculate_pvalue_permutations(group1: &[f64], group2: &[f64], iterations: usize) -> Vec<f64> {
    let mut pvalues = Vec::new();
    for _ in 0..iterations {
        let mut combined: Vec<f64> = [group1, group2].concat();
        combined.shuffle(&mut rand::thread_rng());
        let permuted_group1 = &combined[..group1.len()];
        let permuted_group2 = &combined[group1.len()..];
        let t_test = TTestInd::new(Data::new(permuted_group1), Data::new(permuted_group2));
        pvalues.push(t_test.p_value());
    }
    pvalues
}

fn main() {
    let (group1, group2) = generate_data(30);
    let permutations = 1000;
    let pvalues = calculate_pvalue_permutations(&group1, &group2, permutations);
    let mean_pvalue: f64 = pvalues.iter().sum::<f64>() / pvalues.len() as f64;
    println!("{}", mean_pvalue);
}