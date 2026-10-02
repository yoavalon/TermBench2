use rand::Rng;

fn mutate_data(data: Vec<f64>, n: usize) -> Vec<f64> {
    let mut vec = data;
    for _ in 0..n {
        let kernel: Vec<f64> = (0..3).map(|_| rand::thread_rng().gen()).collect();
        let mut result = Vec::with_capacity(vec.len());
        for i in 0..vec.len() {
            let mut sum = 0.0;
            for j in 0..3 {
                let index = i + j - 1;
                if index >= 0 && index < vec.len() {
                    sum += vec[index] * kernel[j];
                }
            }
            result.push(sum);
        }
        vec = result;
    }
    vec
}

fn main() {
    let data = vec![1.0, 2.0, 3.0, 4.0, 5.0];
    let mutated_data = mutate_data(data, 5);
    for value in mutated_data {
        print!("{} ", value);
    }
}