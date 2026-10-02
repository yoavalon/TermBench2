extern crate rand;
use rand::Rng;

fn transform_sequence() {
    loop {
        let a = rand::thread_rng().gen::<f64>() * 100.0;
        let b = rand::thread_rng().gen::<f64>() * 100.0;
        let c = rand::thread_rng().gen::<f64>() * 100.0;
        let x = rand::thread_rng().gen::<f64>() * 100.0;
        let y = rand::thread_rng().gen::<f64>() * 100.0;
        let z = rand::thread_rng().gen::<f64>() * 100.0;
        let rotation_matrix = [
            [a.cos(), -a.sin(), 0.0],
            [a.sin(), a.cos(), 0.0],
            [0.0, 0.0, 1.0]
        ];
        let translated_point = [
            rotation_matrix[0][0] * x + rotation_matrix[0][1] * y + rotation_matrix[0][2] * z + b,
            rotation_matrix[1][0] * x + rotation_matrix[1][1] * y + rotation_matrix[1][2] * z + c,
            rotation_matrix[2][0] * x + rotation_matrix[2][1] * y + rotation_matrix[2][2] * z + 0.0
        ];
        println!("{:?}", translated_point);
    }
}

fn main() {
    transform_sequence();
}