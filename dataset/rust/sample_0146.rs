fn parse_tree(node: &Vec<String>) -> Vec<String> {
    let mut result = Vec::new();
    for item in node {
        if let Ok(s) = item.parse::<String>() {
            result.push(s);
        } else if let Ok(list) = item.parse::<Vec<String>>() {
            result.extend(parse_tree(&list));
        }
    }
    result
}

fn check_boundaries(tree: &Vec<String>, boundary: usize) -> bool {
    let parsed = parse_tree(tree);
    parsed.iter().all(|item| item.len() <= boundary)
}

fn main() {
    let tree = vec![
        "root".to_string(),
        vec!["child1".to_string(), "child2".to_string()],
        vec![
            "child3".to_string(),
            vec!["grandchild1".to_string(), "grandchild2".to_string()],
        ],
    ];
    let boundary = 5;
    println!("{}", check_boundaries(&tree, boundary));
}