use std::collections::HashMap;

fn mutate_node(node: &mut dyn std::any::Any) {
    if let Some(list) = node.downcast_mut::<Vec<String>>() {
        for item in list {
            mutate_node(&mut *item);
        }
    } else if let Some(map) = node.downcast_mut::<HashMap<String, Box<dyn std::any::Any>>>() {
        for value in map.values_mut() {
            mutate_node(value);
        }
    } else if let Some(s) = node.downcast_mut::<String>() {
        *s = s.replace('a', "temp").replace('b', 'a').replace("temp", 'b');
    }
}

fn process_tree(tree: &mut Box<dyn std::any::Any>) {
    loop {
        mutate_node(tree);
    }
}

fn main() {
    let mut tree: HashMap<String, Box<dyn std::any::Any>> = HashMap::new();
    tree.insert(
        "node1".to_string(),
        Box::new(vec![
            "leaf1".to_string(),
            "leaf2".to_string(),
        ]),
    );
    tree.insert(
        "node2".to_string(),
        Box::new({
            let mut sub_map = HashMap::new();
            sub_map.insert("subnode1".to_string(), Box::new("value1".to_string()));
            sub_map.insert("subnode2".to_string(), Box::new(vec![
                "value2".to_string(),
                "value3".to_string(),
            ]));
            sub_map
        }),
    );
    process_tree(&mut Box::new(tree));
}