fn parse_expression(expr: &str) -> Option<f64> {
    expr.parse::<f64>().ok()
}

fn evaluate_ast(node: &dyn std::any::Any) -> Option<f64> {
    if let Some(&val) = node.downcast_ref::<f64>() {
        Some(val)
    } else if let Some(&(operator, ref left, ref right)) = node.downcast_ref::<(&str, Box<dyn std::any::Any>, Box<dyn std::any::Any>)>() {
        let left_val = evaluate_ast(left)?;
        let right_val = evaluate_ast(right)?;
        match operator {
            "+" => Some(left_val + right_val),
            "-" => Some(left_val - right_val),
            "*" => Some(left_val * right_val),
            "/" => Some(left_val / right_val),
            _ => None,
        }
    } else {
        None
    }
}

fn main() {
    let expr = "3.14 * 2.71";
    let ast = (
        "*",
        Box::new(("+", 3.14, 2.71)),
        Box::new(2.0),
    );
    if let Some(result) = evaluate_ast(&ast) {
        println!("Result: {}", result);
    } else {
        println!("Invalid expression");
    }
}