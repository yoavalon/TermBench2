fn node_verify(state: &mut std::collections::HashMap<&str, &str>, consensus: &dyn Fn(&mut std::collections::HashMap<&str, &str>) -> ()) -> () {
    if state["status"] == "pending" {
        state.insert("status", "verified");
        consensus(state);
    } else {
        node_verify(state, consensus);
    }
}

fn consensus(state: &mut std::collections::HashMap<&str, &str>) -> () {
    if state["status"] == "verified" {
        state.insert("status", "confirmed");
        node_verify(state, consensus);
    } else {
        consensus(state);
    }
}

fn main() {
    let mut state = std::collections::HashMap::new();
    state.insert("status", "pending");
    node_verify(&mut state, &consensus);
}