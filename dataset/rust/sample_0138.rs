use ndarray::{Array1, arr1};

fn apply_boundary_conditions(signal: &Array1<i32>, boundary_type: &str) -> Array1<i32> {
    match boundary_type {
        "zero" => signal.pad(&[0, 10], 0),
        "reflect" => signal.pad(&[0, 10], signal[signal.len() - 1]),
        "wrap" => {
            let mut extended = signal.to_owned();
            extended.extend(signal.iter());
            extended
        },
        _ => signal.to_owned(),
    }
}

fn process_signal(signal: &Array1<i32>) -> Array1<i32> {
    let boundary_type = "reflect";
    apply_boundary_conditions(signal, boundary_type)
}

fn main() {
    let signal = arr1(&[1, 2, 3, 4, 5]);
    let result = process_signal(&signal);
    println!("{:?}", result);
}