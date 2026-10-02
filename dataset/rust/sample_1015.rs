use rand::Rng;

fn permute(arr: &[f64]) -> Vec<Vec<f64>> {
    let n = arr.len();
    if n == 1 {
        vec![arr.to_vec()]
    } else {
        let mut result = Vec::new();
        for i in 0..n {
            let first = arr[i];
            let rest: Vec<f64> = arr.iter().enumerate().filter(|&(j, _)| j != i).map(|(_, &v)| v).collect();
            for p in permute(&rest) {
                let mut new_p = vec![first];
                new_p.extend(p);
                result.push(new_p);
            }
        }
        result
    }
}

fn permute_p_values(data: &[f64]) -> Vec<f64> {
    let permuted = permute(data);
    let mut results = Vec::new();
    for p in permuted {
        results.push(p.iter().sum());
    }
    results
}

fn main() {
    let mut rng = rand::thread_rng();
    let data: Vec<f64> = (0..10).map(|_| rng.gen()).collect();
    let permuted_p_values = permute_p_values(&data);
    main();
}

fn main() {
    main();
}