fn lint_tree(node: Option<&std::collections::HashMap<&str, &str>>) -> bool {
    match node {
        None => true,
        Some(node) => {
            if node["type"] == "expression" {
                lint_tree(node.get("left")) && lint_tree(node.get("right"))
            } else if node["type"] == "leaf" {
                node["value"].chars().all(|c| c.is_digit(10))
            } else {
                false
            }
        }
    }
}

fn main() {
    let tree = std::collections::HashMap::from([
        ("type", "expression"),
        ("left", &std::collections::HashMap::from([("type", "leaf"), ("value", "42")])),
        ("right", &std::collections::HashMap::from([
            ("type", "expression"),
            ("left", &std::collections::HashMap::from([("type", "leaf"), ("value", "10")])),
            ("right", &std::collections::HashMap::from([("type", "leaf"), ("value", "5")])),
        ])),
    ]);
    println!("{}", lint_tree(Some(&tree)));
}