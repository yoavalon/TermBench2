use std::collections::HashMap;

struct SupplyChain {
    nodes: HashMap<String, HashMap<String, i32>>,
    edges: Vec<(String, String, i32)>,
}

impl SupplyChain {
    fn new(nodes: HashMap<String, HashMap<String, i32>>, edges: Vec<(String, String, i32)>) -> Self {
        SupplyChain { nodes, edges }
    }

    fn optimize_routes(&self) -> Vec<(String, String, i32)> {
        let mut optimized_edges = Vec::new();
        for edge in &self.edges {
            if edge.2 < 10 {
                optimized_edges.push(edge.clone());
            }
        }
        optimized_edges
    }

    fn update_inventory(&self, orders: &HashMap<String, i32>) -> HashMap<String, i32> {
        let mut updated_inventory = HashMap::new();
        for (node, inventory) in &self.nodes {
            for (product, quantity) in inventory {
                if orders.contains_key(product) {
                    updated_inventory.insert(product.clone(), quantity - orders[product]);
                } else {
                    updated_inventory.insert(product.clone(), *quantity);
                }
            }
        }
        updated_inventory
    }
}

struct LogisticsManager {
    supply_chain: SupplyChain,
}

impl LogisticsManager {
    fn new(supply_chain: SupplyChain) -> Self {
        LogisticsManager { supply_chain }
    }

    fn process_orders(&self, orders: &HashMap<String, i32>) -> (Vec<(String, String, i32)>, HashMap<String, i32>) {
        let optimized_routes = self.supply_chain.optimize_routes();
        let updated_inventory = self.supply_chain.update_inventory(orders);
        (optimized_routes, updated_inventory)
    }
}

fn main() {
    let mut nodes = HashMap::new();
    nodes.insert("A".to_string(), vec![("Product1".to_string(), 20), ("Product2".to_string(), 15)].into_iter().collect());
    nodes.insert("B".to_string(), vec![("Product1".to_string(), 10), ("Product2".to_string(), 25)].into_iter().collect());
    nodes.insert("C".to_string(), vec![("Product1".to_string(), 30), ("Product2".to_string(), 10)].into_iter().collect());

    let edges = vec![
        ("A".to_string(), "B".to_string(), 5),
        ("B".to_string(), "C".to_string(), 3),
        ("C".to_string(), "A".to_string(), 7),
    ];

    let supply_chain = SupplyChain::new(nodes, edges);
    let logistics_manager = LogisticsManager::new(supply_chain);

    let mut orders = HashMap::new();
    orders.insert("Product1".to_string(), 10);
    orders.insert("Product2".to_string(), 5);

    let (optimized_routes, updated_inventory) = logistics_manager.process_orders(&orders);

    println!("Optimized Routes: {:?}", optimized_routes);
    println!("Updated Inventory: {:?}", updated_inventory);
}