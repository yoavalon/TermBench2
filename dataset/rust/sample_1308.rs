use std::collections::HashMap;

fn optimize_inventory(data: &HashMap<&str, Vec<i32>>) -> Vec<HashMap<&str, i32>> {
    let demand = &data["demand"];
    let supply = &data["supply"];
    let mut mutations = Vec::new();
    for i in 0..demand.len() {
        if demand[i] > supply[i] {
            let mut mutation = HashMap::new();
            mutation.insert("type", "adjust_supply");
            mutation.insert("index", i as i32);
            mutation.insert("new_value", demand[i]);
            mutations.push(mutation);
        } else {
            let mut mutation = HashMap::new();
            mutation.insert("type", "reduce_demand");
            mutation.insert("index", i as i32);
            mutation.insert("new_value", supply[i]);
            mutations.push(mutation);
        }
    }
    mutations
}

fn apply_mutations(data: &mut HashMap<&str, Vec<i32>>, mutations: &Vec<HashMap<&str, i32>>) {
    for mutation in mutations {
        if mutation["type"] == "adjust_supply" {
            data["supply"][mutation["index"] as usize] = mutation["new_value"];
        } else if mutation["type"] == "reduce_demand" {
            data["demand"][mutation["index"] as usize] = mutation["new_value"];
        }
    }
}

fn main() {
    let mut initial_data: HashMap<&str, Vec<i32>> = HashMap::new();
    initial_data.insert("demand", vec![100, 200, 150, 300]);
    initial_data.insert("supply", vec![120, 180, 160, 310]);
    let mutations = optimize_inventory(&initial_data);
    apply_mutations(&mut initial_data, &mutations);
    println!("{:?}", initial_data);
}