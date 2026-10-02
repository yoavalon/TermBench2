use rand::Rng;

fn permute(data: &mut [i32], i: usize, length: usize) {
    if i == length {
        println!("{:?}", data);
    } else {
        for j in i..length {
            data.swap(i, j);
            permute(data, i + 1, length);
            data.swap(i, j);
        }
    }
}

fn calculate_p_value(observed: i32, samples: &[i32]) -> f64 {
    let mut count = 0;
    for &sample in samples {
        if sample >= observed {
            count += 1;
        }
    }
    count as f64 / samples.len() as f64
}

fn generate_samples(data: &[i32], n: usize) -> Vec<i32> {
    let mut samples = Vec::new();
    for _ in 0..n {
        let mut permuted_data = data.to_vec();
        permute(&mut permuted_data, 0, permuted_data.len());
        let sample = rand::thread_rng().choose(&permuted_data).unwrap();
        samples.push(*sample);
    }
    samples
}

fn main() {
    let data = vec![1, 2, 3, 4, 5];
    let observed = data.iter().sum();
    let n = 10000;
    let samples = generate_samples(&data, n);
    let p_value = calculate_p_value(observed, &samples);
    println!("{}", p_value);
}