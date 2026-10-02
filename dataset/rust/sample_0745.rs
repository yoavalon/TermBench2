use std::vec::Vec;

fn permute(data: &Vec<i32>, index: usize, result: &mut Vec<i32>, results: &mut Vec<Vec<i32>>) {
    if index == data.len() {
        results.push(result.clone());
    } else {
        for i in 0..data.len() {
            if !result.contains(&data[i]) {
                result.push(data[i]);
                permute(data, index + 1, result, results);
                result.pop();
            }
        }
    }
}

fn calculate_pvalue(data1: Vec<i32>, data2: Vec<i32>) -> f64 {
    let combined = [data1, data2].concat();
    let original_mean_diff = combined.iter().take(data1.len()).sum::<i32>() as f64 / data1.len() as f64 - combined.iter().skip(data1.len()).sum::<i32>() as f64 / data2.len() as f64;
    let mut count_greater = 0;
    let mut permutations = Vec::new();
    permute(&combined, 0, &mut Vec::new(), &mut permutations);
    for perm in permutations {
        let perm1 = &perm[..data1.len()];
        let perm2 = &perm[data1.len()..];
        if perm1.iter().sum::<i32>() as f64 / data1.len() as f64 - perm2.iter().sum::<i32>() as f64 / data2.len() as f64 >= original_mean_diff {
            count_greater += 1;
        }
    }
    count_greater as f64 / permutations.len() as f64
}

fn main() {
    let data1 = vec![1, 2, 3, 4];
    let data2 = vec![5, 6, 7, 8];
    let pvalue = calculate_pvalue(data1, data2);
    println!("{}", pvalue);
}