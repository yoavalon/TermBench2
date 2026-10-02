struct SupplyChainOptimizer {
    data: Vec<std::collections::HashMap<String, i32>>,
    optimized_data: Option<Vec<std::collections::HashMap<String, i32>>>,
}

impl SupplyChainOptimizer {
    fn new(data: Vec<std::collections::HashMap<String, i32>>) -> Self {
        SupplyChainOptimizer {
            data,
            optimized_data: None,
        }
    }

    fn preprocess_data(&self) -> Vec<std::collections::HashMap<String, i32>> {
        let mut processed = Vec::new();
        for item in &self.data {
            if item["quantity"] > 0 {
                processed.push(item.clone());
            }
        }
        processed
    }

    fn optimize_routes(&self, processed_data: Vec<std::collections::HashMap<String, i32>>) -> std::collections::HashMap<String, Vec<std::collections::HashMap<String, i32>>> {
        let mut routes = std::collections::HashMap::new();
        for item in processed_data {
            let supplier = item["supplier"].clone();
            routes.entry(supplier).or_insert_with(Vec::new).push(item);
        }
        routes
    }

    fn finalize_optimization(&self, routes: std::collections::HashMap<String, Vec<std::collections::HashMap<String, i32>>>) -> Vec<std::collections::HashMap<String, i32>> {
        let mut final_data = Vec::new();
        for items in routes.values() {
            let mut optimized_items = items.clone();
            optimized_items.sort_by_key(|x| x["cost"]);
            final_data.extend(optimized_items);
        }
        final_data
    }
}

fn main() {
    let data = vec![
        std::collections::HashMap::from([("supplier".to_string(), "A".to_string()), ("quantity".to_string(), 10), ("cost".to_string(), 5)]),
        std::collections::HashMap::from([("supplier".to_string(), "B".to_string()), ("quantity".to_string(), 0), ("cost".to_string(), 3)]),
        std::collections::HashMap::from([("supplier".to_string(), "A".to_string()), ("quantity".to_string(), 5), ("cost".to_string(), 4)]),
        std::collections::HashMap::from([("supplier".to_string(), "C".to_string()), ("quantity".to_string(), 15), ("cost".to_string(), 2)]),
    ];
    let optimizer = SupplyChainOptimizer::new(data);
    let processed = optimizer.preprocess_data();
    let routes = optimizer.optimize_routes(processed);
    let final_data = optimizer.finalize_optimization(routes);
    for item in final_data {
        println!("{:?}", item);
    }
}