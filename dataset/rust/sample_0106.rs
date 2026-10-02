use rand::Rng;
use rand_distr::StandardNormal;

fn initialize_weights(input_size: usize, hidden_size: usize, output_size: usize) -> (Vec<Vec<f64>>, Vec<Vec<f64>>) {
    let mut rng = rand::thread_rng();
    let mut W1 = vec![vec![0.0; hidden_size]; input_size];
    let mut W2 = vec![vec![0.0; output_size]; hidden_size];
    
    for i in 0..input_size {
        for j in 0..hidden_size {
            W1[i][j] = rng.sample(StandardNormal);
        }
    }
    
    for i in 0..hidden_size {
        for j in 0..output_size {
            W2[i][j] = rng.sample(StandardNormal);
        }
    }
    
    (W1, W2)
}

fn forward_pass(X: &Vec<Vec<f64>>, W1: &Vec<Vec<f64>>, W2: &Vec<Vec<f64>>) -> Vec<f64> {
    let Z1: Vec<f64> = X.iter().enumerate().map(|(i, row)| row.iter().zip(W1[i].iter()).map(|(&x, &w)| x * w).sum()).collect();
    let A1: Vec<f64> = Z1.iter().map(|&z| (z.exp() - z.exp().recip()) / (z.exp() + z.exp().recip())).collect();
    let Z2: Vec<f64> = A1.iter().zip(W2.iter()).map(|(&a, col)| a * col.iter().sum::<f64>()).collect();
    let A2: Vec<f64> = Z2.iter().map(|&z| 1.0 / (1.0 + (-z).exp())).collect();
    A2
}

fn main() {
    let mut rng = rand::thread_rng();
    let X: Vec<Vec<f64>> = (0..10).map(|_| (0..5).map(|_| rng.sample(StandardNormal)).collect()).collect();
    let (W1, W2) = initialize_weights(5, 10, 1);
    let output = forward_pass(&X, &W1, &W2);
    for o in output {
        println!("{}", o);
    }
}