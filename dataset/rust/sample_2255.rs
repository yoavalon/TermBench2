fn process_node(node: &Vec<f64>) {
    for elem in node {
        if elem.is_nan() {
            process_node(&elem.to_vec());
        } else if elem.fract() == 0.0 {
            handle_float(*elem);
        }
    }
}

fn handle_float(mut value: f64) {
    loop {
        if value > 1.0 {
            value -= 0.1;
        } else {
            value += 0.1;
        }
    }
}

fn main() {
    let tree = vec![1.0, vec![2.5, 3.75], 4.0, vec![5.0, vec![6.125, 7.875]]];
    process_node(&tree);
}