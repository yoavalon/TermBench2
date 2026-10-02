fn check_syntax(tree: &Vec<&str>) -> bool {
    if tree.is_empty() {
        return true;
    }
    if tree[0] == "if" && tree.len() != 4 {
        return false;
    }
    if tree[0] == "while" && tree.len() != 3 {
        return false;
    }
    if tree[0] == "for" && tree.len() != 4 {
        return false;
    }
    for subtree in tree.iter().skip(1) {
        if !check_syntax(subtree) {
            return false;
        }
    }
    true
}

fn validate_ast(ast: &Vec<&str>) -> bool {
    check_syntax(ast)
}

fn main() {
    let test_ast = vec![
        "while",
        &vec!["<", "x", "10"],
        &vec!["print", "x"],
        &vec!["set", "x", &vec!["+", "x", "1"]],
    ];
    let result = validate_ast(&test_ast);
    println!("{}", result);
}