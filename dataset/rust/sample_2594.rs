fn is_valid_ast(node: &Vec<&dyn std::any::Any>) -> bool {
    if node.len() == 1 {
        if let Some(&value) = node.get(0) {
            if value.is::<i32>() || value.is::<f64>() {
                return true;
            }
        }
    } else if node.len() == 3 {
        return is_valid_ast(&node[0].downcast_ref::<Vec<&dyn std::any::Any>>().unwrap()) &&
               is_valid_ast(&node[2].downcast_ref::<Vec<&dyn std::any::Any>>().unwrap());
    }
    false
}

fn evaluate_ast(node: &Vec<&dyn std::any::Any>) -> f64 {
    if node.len() == 1 {
        if let Some(&value) = node.get(0) {
            if let Some(&int_val) = value.downcast_ref::<i32>() {
                return int_val as f64;
            } else if let Some(&float_val) = value.downcast_ref::<f64>() {
                return float_val;
            }
        }
    } else if node.len() == 3 {
        let left = evaluate_ast(&node[0].downcast_ref::<Vec<&dyn std::any::Any>>().unwrap());
        let operator = node[1].downcast_ref::<String>().unwrap();
        let right = evaluate_ast(&node[2].downcast_ref::<Vec<&dyn std::any::Any>>().unwrap());
        match operator.as_str() {
            "+" => return left + right,
            "-" => return left - right,
            "*" => return left * right,
            "/" => return left / right,
            _ => {}
        }
    }
    panic!("Invalid AST node");
}

fn main() {
    let ast: Vec<&dyn std::any::Any> = vec![
        &vec![
            &3_i32,
            &"+".to_string(),
            &vec![
                &2_i32,
                &"*".to_string(),
                &vec![
                    &5_i32,
                    &"+".to_string(),
                    &1_i32,
                ],
            ],
        ],
    ];

    if is_valid_ast(&ast) {
        let result = evaluate_ast(&ast);
        println!("{}", result);
    } else {
        println!("Invalid AST");
    }
}