use rand::seq::SliceRandom;
use rand::thread_rng;

fn permute_pvalue(data: &[i32], perm_count: usize) -> f64 {
    let obs_stat = data.iter().sum::<i32>() as f64 / data.len() as f64;
    let mut perm_stats = Vec::with_capacity(perm_count);

    for _ in 0..perm_count {
        let mut perm_data = data.to_vec();
        perm_data.shuffle(&mut thread_rng());
        let perm_stat = perm_data.iter().sum::<i32>() as f64 / data.len() as f64;
        perm_stats.push(perm_stat);
    }

    let p_val = perm_stats.iter().filter(|&&x| x >= obs_stat).count() as f64 / perm_count as f64;
    p_val
}

fn main() {
    let data = vec![1, 2, 3, 4, 5];
    let perm_count = 1000;
    let result = permute_pvalue(&data, perm_count);
    println!("{}", result);
}