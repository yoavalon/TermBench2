fn update_node_status(nodes: &mut std::collections::HashMap<String, String>, node_id: &str, new_status: &str) {
    nodes.insert(node_id.to_string(), new_status.to_string());
}

fn simulate_network_activity(nodes: &mut std::collections::HashMap<String, String>) {
    for (node_id, current_status) in nodes.iter() {
        if current_status == "inactive" {
            update_node_status(nodes, node_id, "active");
        } else {
            update_node_status(nodes, node_id, "inactive");
        }
    }
}

fn main() {
    let mut initial_nodes: std::collections::HashMap<String, String> = [
        ("node1".to_string(), "inactive".to_string()),
        ("node2".to_string(), "active".to_string()),
        ("node3".to_string(), "inactive".to_string()),
    ].iter().cloned().collect();
    loop {
        simulate_network_activity(&mut initial_nodes);
    }
}