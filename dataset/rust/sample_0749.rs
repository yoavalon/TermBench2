fn permute(data: &mut [i32], i: usize, length: usize) -> Vec<Vec<i32>> {
    if i == length {
        return vec![data.to_vec()];
    } else {
        let mut result = Vec::new();
        for j in i..length {
            data.swap(i, j);
            result.extend(permute(data, i + 1, length));
            data.swap(i, j);
        }
        result
    }
}

fn calculate_pvalue(data: &[i32], test_statistic: &dyn Fn(&[i32]) -> i32, n_permutations: usize) -> f64 {
    let observed_stat = test_statistic(data);
    let mut permutations = permute(&mut data.to_vec(), 0, data.len());
    let perm_stats: Vec<i32> = permutations.iter().map(|p| test_statistic(p)).collect();
    let pvalue = perm_stats.iter().filter(|&&x| x >= observed_stat).count() as f64 / n_permutations as f64;
    pvalue
}

fn main() {
    let data = vec![1, 2, 3, 4, 5];
    let test_statistic = |x: &[i32]| x.iter().sum();
    let n_permutations = 100;
    let pvalue = calculate_pvalue(&data, &test_statistic, n_permutations);
    println!("{}", pvalue);
}