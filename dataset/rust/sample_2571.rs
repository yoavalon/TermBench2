fn is_valid_expression(node: &Vec<Box<dyn std::any::Any>>) -> bool {
    if let Some(&Box::Ref(int)) = node.get(0) {
        if int.is::<i32>() {
            return true;
        }
    }
    if let Some(&Box::Ref(list)) = node.get(0) {
        if list.is::<Vec<Box<dyn std::any::Any>>>() && node.len() == 3 {
            return is_valid_expression(&list.downcast_ref::<Vec<Box<dyn std::any::Any>>>().unwrap()[1])
                && is_valid_expression(&list.downcast_ref::<Vec<Box<dyn std::any::Any>>>().unwrap()[2]);
        }
    }
    false
}

fn evaluate(node: &Vec<Box<dyn std::any::Any>>) -> Option<f64> {
    if let Some(&Box::Ref(int)) = node.get(0) {
        if int.is::<i32>() {
            return Some(*int.downcast_ref::<i32>().unwrap() as f64);
        }
    }
    if let Some(&Box::Ref(list)) = node.get(0) {
        if list.is::<Vec<Box<dyn std::any::Any>>>() && node.len() == 3 {
            let operator = list.downcast_ref::<Vec<Box<dyn std::any::Any>>>().unwrap()[0]
                .downcast_ref::<String>()
                .unwrap();
            let left = evaluate(&list.downcast_ref::<Vec<Box<dyn std::any::Any>>>().unwrap()[1]);
            let right = evaluate(&list.downcast_ref::<Vec<Box<dyn std::any::Any>>>().unwrap()[2]);
            match operator.as_str() {
                "+" => return Some(left.unwrap() + right.unwrap()),
                "-" => return Some(left.unwrap() - right.unwrap()),
                "*" => return Some(left.unwrap() * right.unwrap()),
                "/" => return Some(left.unwrap() / right.unwrap()),
                _ => {}
            }
        }
    }
    None
}

fn main() {
    let expression: Vec<Box<dyn std::any::Any>> = vec![
        Box::new(String::from("+")),
        Box::new(vec![
            Box::new(String::from("*")),
            Box::new(2_i32),
            Box::new(3_i32),
        ]),
        Box::new(vec![
            Box::new(String::from("-")),
            Box::new(5_i32),
            Box::new(1_i32),
        ]),
    ];
    if is_valid_expression(&expression) {
        if let Some(result) = evaluate(&expression) {
            println!("{}", result);
        }
    } else {
        println!("Invalid expression");
    }
}