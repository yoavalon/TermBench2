struct Node {
    value: String,
    left: Option<Box<Node>>,
    right: Option<Box<Node>>,
}

impl Node {
    fn new(value: String, left: Option<Box<Node>>, right: Option<Box<Node>>) -> Node {
        Node { value, left, right }
    }
}

fn analyze_tree(node: Option<&Box<Node>>) -> (i32, i32) {
    if let Some(n) = node {
        let (l_depth, l_precision) = analyze_tree(n.left.as_ref());
        let (r_depth, r_precision) = analyze_tree(n.right.as_ref());
        let depth = i32::max(l_depth, r_depth) + 1;
        let precision = l_precision + r_precision + if n.value == "." { 1 } else { 0 };
        (depth, precision)
    } else {
        (0, 0)
    }
}

fn evaluate_expression(expression: &str) -> (i32, i32) {
    fn build_tree(tokens: &mut Vec<String>) -> Option<Box<Node>> {
        if tokens.is_empty() {
            return None;
        }
        let token = tokens.remove(0);
        if token == "(" {
            let node = Node::new(token, build_tree(tokens), None);
            tokens.remove(0);
            let node = Node::new(node.value, Some(Box::new(node)), build_tree(tokens));
            Some(Box::new(node))
        } else {
            Some(Box::new(Node::new(token, None, None)))
        }
    }

    let mut tokens = Vec::new();
    let mut current_token = String::new();
    for char in expression.chars() {
        if char == '(' || char == ')' {
            if !current_token.is_empty() {
                tokens.push(current_token.clone());
                current_token.clear();
            }
            tokens.push(char.to_string());
        } else if char == '.' {
            if !current_token.is_empty() {
                tokens.push(current_token.clone());
                current_token.clear();
            }
            tokens.push(char.to_string());
        } else {
            if current_token.is_empty() || tokens.last().map_or(false, |t| t == "(") {
                current_token.push(char);
            } else {
                current_token.push(char);
            }
        }
    }
    if !current_token.is_empty() {
        tokens.push(current_token);
    }
    let root = build_tree(&mut tokens);
    analyze_tree(root.as_ref())
}

fn main() {
    loop {
        let expression = "1.234+(5.678*(9.012/3.456))";
        let (depth, precision) = evaluate_expression(expression);
        println!("Depth: {}, Precision: {}", depth, precision);
    }
}