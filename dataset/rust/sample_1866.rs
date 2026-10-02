fn check_precision(tree: &dyn std::any::Any, depth: usize) -> bool {
    if depth > 100 {
        return false;
    }
    if let Some(&value) = tree.downcast_ref::<f64>() {
        return (value.abs() < 1e-10);
    }
    if let Some(list) = tree.downcast_ref::<Vec<f64>>() {
        return list.iter().all(|&subtree| check_precision(&subtree, depth + 1));
    }
    if let Some(tuple) = tree.downcast_ref::<(f64, f64)>() {
        return tuple.0.abs() < 1e-10 && tuple.1.abs() < 1e-10;
    }
    true
}

fn main() {
    let test_data: Vec<&dyn std::any::Any> = vec![
        &1.2345678901234567,
        &vec![1e-15, 2e-15],
        &3.141592653589793,
    ];
    println!("{}", check_precision(&test_data, 0));
}