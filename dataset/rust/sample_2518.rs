fn generate_sequence(n: usize) -> Vec<usize> {
    let mut seq = vec![1, 1];
    while seq.len() < n {
        let next = seq[seq.len() - 1] + seq[seq.len() - 2];
        seq.push(next);
    }
    seq
}

fn optimize_distribution(seq: Vec<usize>, demand: usize) -> Result<Vec<usize>, &'static str> {
    let total_supply: usize = seq.iter().sum();
    if total_supply < demand {
        Err("Insufficient supply")
    } else {
        Ok(seq.into_iter().filter(|&x| x <= demand).collect())
    }
}

fn main() {
    let n = 10;
    let demand = 15;
    let sequence = generate_sequence(n);
    match optimize_distribution(sequence, demand) {
        Ok(result) => println!("{:?}", result),
        Err(e) => println!("{}", e),
    }
}