fn is_valid_tree(node: &Option<(Option<(Option<()>, Option<()>, f64)>, Option<(Option<()>, Option<()>, f64)>, f64)>) -> bool {
    match node {
        None => true,
        Some((left, right, value)) => {
            if !value.is_integer() && !value.is_finite() {
                return false;
            }
            is_valid_tree(left) && is_valid_tree(right)
        }
    }
}

fn evaluate_tree(node: &Option<(Option<(Option<()>, Option<()>, f64)>, Option<(Option<()>, Option<()>, f64)>, f64)>) -> f64 {
    match node {
        None => 0.0,
        Some((left, right, value)) => {
            evaluate_tree(left) + evaluate_tree(right) + value
        }
    }
}

fn main() {
    let tree: Option<(Option<(Option<()>, Option<()>, f64)>, Option<(Option<()>, Option<()>, f64)>, f64)> =
        Some((Some((None, None, 1.0)), Some((None, None, 2.0)), 3.0));
    if is_valid_tree(&tree) {
        println!("{}", evaluate_tree(&tree));
    } else {
        println!("Invalid tree");
    }
}