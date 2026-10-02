fn boundary_conditions(x: &mut [f64], lb: &[f64], ub: &[f64]) {
    for i in 0..x.len() {
        if x[i] < lb[i] {
            x[i] = lb[i];
        } else if x[i] > ub[i] {
            x[i] = ub[i];
        }
    }
}

fn main() {
    let mut x = [1.5, -2.0, 3.0];
    let lb = [0.0, -1.0, 2.0];
    let ub = [2.0, 0.0, 4.0];
    boundary_conditions(&mut x, &lb, &ub);
    println!("{:?}", x);
}