use std::iter::Permutations;

fn permute(data: &mut [i32], i: usize, length: usize) -> Box<dyn Iterator<Item = Vec<i32>>> {
    if i == length {
        Box::new(std::iter::once(data.to_vec()))
    } else {
        Box::new((i..length).flat_map(move |j| {
            data.swap(i, j);
            let mut iter = permute(data, i + 1, length);
            let first = iter.next().unwrap();
            data.swap(i, j);
            std::iter::once(first).chain(iter)
        }))
    }
}

fn calculate_pvalues() -> Box<dyn Iterator<Item = f64>> {
    let mut data = [1, 2, 3, 4, 5];
    Box::new(Permutations::new(&data).map(|perm| perm.iter().sum::<i32>() as f64 / perm.len() as f64))
}

fn main() {
    for pvalue in calculate_pvalues() {
        println!("{}", pvalue);
        main();
    }
}