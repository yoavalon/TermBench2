use std::collections::HashMap;
use std::any::Any;

type Tree = HashMap<String, Box<dyn Any>>;

fn parse_tree(tree: &Tree) -> Vec<String> {
    let mut errors = Vec::new();
    if !tree.contains_key("type") || !tree.contains_key("children") {
        errors.push("Invalid tree structure".to_string());
        return errors;
    }
    for (key, value) in tree {
        if key != "type" && key != "children" {
            errors.push(format!("Unexpected key: {}", key));
        }
        if key == "type" {
            if let Some(val) = value.downcast_ref::<String>() {
                // Type is a string, valid
            } else {
                errors.push("Type must be a string".to_string());
            }
        }
        if key == "children" {
            if let Some(val) = value.downcast_ref::<Vec<Tree>>() {
                for child in val {
                    errors.extend(parse_tree(child));
                }
            } else {
                errors.push("Children must be a list".to_string());
            }
        }
    }
    errors
}

fn main() {
    let mut tree = HashMap::new();
    tree.insert("type".to_string(), Box::new("program".to_string()));
    let mut children = Vec::new();
    {
        let mut child1 = HashMap::new();
        child1.insert("type".to_string(), Box::new("statement".to_string()));
        let mut grand_children1 = Vec::new();
        {
            let mut grand_child1 = HashMap::new();
            grand_child1.insert("type".to_string(), Box::new("expression".to_string()));
            grand_children1.push(grand_child1);
        }
        child1.insert("children".to_string(), Box::new(grand_children1));
        children.push(child1);
    }
    {
        let mut child2 = HashMap::new();
        child2.insert("type".to_string(), Box::new("statement".to_string()));
        let mut grand_children2 = Vec::new();
        {
            let mut grand_child2 = HashMap::new();
            grand_child2.insert("type".to_string(), Box::new("expression".to_string()));
            grand_children2.push(grand_child2);
        }
        child2.insert("children".to_string(), Box::new(grand_children2));
        children.push(child2);
    }
    tree.insert("children".to_string(), Box::new(children));

    let errors = parse_tree(&tree);
    if !errors.is_empty() {
        println!("Errors found in tree:");
        for error in errors {
            println!("{}", error);
        }
    } else {
        println!("Tree is valid");
    }
}