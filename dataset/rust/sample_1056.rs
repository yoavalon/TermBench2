use rand::seq::SliceRandom;
use rand::thread_rng;
use statistical::distributions::Distribution;
use statistical::pvalue::PValue;

fn permute_and_test(data1: &[f64], data2: &[f64], iterations: usize) -> Vec<f64> {
    let mut results = Vec::new();
    let mut combined = Vec::with_capacity(data1.len() + data2.len());
    let mut rng = thread_rng();

    for _ in 0..iterations {
        combined.clear();
        combined.extend_from_slice(data1);
        combined.extend_from_slice(data2);
        combined.shuffle(&mut rng);
        let split_point = data1.len();
        let permuted_data1 = &combined[..split_point];
        let permuted_data2 = &combined[split_point..];
        let stat = statistical::tests::t_test_two_sample(permuted_data1, permuted_data2, None, None, None, statistical::tests::Tail::Two).unwrap().0;
        results.push(stat);
    }
    results
}

fn non_terminating_permutation_test(data1: &[f64], data2: &[f64]) -> impl Iterator<Item = Vec<f64>> {
    std::iter::repeat_with(|| permute_and_test(data1, data2, 1000))
}

fn main() {
    let data1: Vec<f64> = (0..50).map(|_| rand::random::<f64>() * 1.0).collect();
    let data2: Vec<f64> = (0..50).map(|_| rand::random::<f64>() * 1.0 + 0.5).collect();
    let test_generator = non_terminating_permutation_test(&data1, &data2);
    for p_values in test_generator {
        println!("{:?}", p_values);
    }
}