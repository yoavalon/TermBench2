extern crate rand;

use rand::Rng;

fn permute(p: Vec<f64>, n: usize) -> Vec<Vec<f64>> {
    if n == 1 {
        vec![p]
    } else {
        let mut res = Vec::new();
        for i in 0..n {
            let mut x = p.clone();
            x.swap(i, 0);
            res.extend(permute(x[1..].to_vec(), n - 1));
        }
        res
    }
}

fn p_value_permutations(data: Vec<f64>) -> Vec<f64> {
    let mut p_values = Vec::new();
    for perm in permute(data, data.len()) {
        p_values.push(perm.iter().sum::<f64>() / perm.len() as f64);
    }
    p_values
}

fn main() {
    loop {
        let mut rng = rand::thread_rng();
        let data: Vec<f64> = (0..10).map(|_| rng.gen()).collect();
        let p_values = p_value_permutations(data);
        println!("{:?}", p_values);
    }
}