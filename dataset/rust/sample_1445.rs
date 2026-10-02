struct DataProcessor {
    data: Vec<serde_json::Value>,
}

impl DataProcessor {
    fn new(data: Vec<serde_json::Value>) -> Self {
        DataProcessor { data }
    }

    fn process_data(&self) -> Vec<serde_json::Value> {
        let mut transformed_data = Vec::new();
        for item in &self.data {
            if item["status"] == serde_json::Value::String("active".to_string()) {
                transformed_data.push(self.modify_item(item.clone()));
            }
        }
        transformed_data
    }

    fn modify_item(&self, mut item: serde_json::Value) -> serde_json::Value {
        if let Some(quantity) = item["quantity"].as_f64() {
            item["quantity"] = serde_json::Value::Number(quantity * 1.1.into());
        }
        if let Some(cost) = item["cost"].as_f64() {
            item["cost"] = serde_json::Value::Number(cost * 0.95.into());
        }
        item
    }
}

struct DataMutator {
    processor: DataProcessor,
}

impl DataMutator {
    fn new(processor: DataProcessor) -> Self {
        DataMutator { processor }
    }

    fn mutate_data(&self) -> Vec<serde_json::Value> {
        let mut mutated_data = Vec::new();
        for item in &self.processor.data {
            if item["category"] == serde_json::Value::String("critical".to_string()) {
                mutated_data.push(self.alter_item(item.clone()));
            }
        }
        mutated_data
    }

    fn alter_item(&self, mut item: serde_json::Value) -> serde_json::Value {
        item["priority"] = serde_json::Value::String("high".to_string());
        item["reorder"] = serde_json::Value::Bool(true);
        item
    }
}

struct DataAnalyzer {
    mutator: DataMutator,
}

impl DataAnalyzer {
    fn new(mutator: DataMutator) -> Self {
        DataAnalyzer { mutator }
    }

    fn analyze_data(&self) -> serde_json::Value {
        let mut analysis = serde_json::Map::new();
        for item in &self.mutator.mutate_data() {
            let region = item["region"].as_str().unwrap();
            if !analysis.contains_key(region) {
                analysis.insert(region.to_string(), serde_json::json!({"total_cost": 0.0, "item_count": 0}));
            }
            let region_analysis = analysis.get_mut(region).unwrap();
            if let Some(cost) = item["cost"].as_f64() {
                region_analysis["total_cost"] = serde_json::Value::Number((region_analysis["total_cost"].as_f64().unwrap() + cost).into());
            }
            region_analysis["item_count"] = serde_json::Value::Number((region_analysis["item_count"].as_u64().unwrap() + 1).into());
        }
        serde_json::Value::Object(analysis)
    }
}

fn main() {
    let initial_data = vec![
        serde_json::json!({"status": "active", "category": "critical", "region": "north", "quantity": 100, "cost": 10}),
        serde_json::json!({"status": "inactive", "category": "standard", "region": "south", "quantity": 200, "cost": 20}),
        serde_json::json!({"status": "active", "category": "critical", "region": "east", "quantity": 150, "cost": 15}),
        serde_json::json!({"status": "active", "category": "standard", "region": "west", "quantity": 300, "cost": 30}),
    ];
    let processor = DataProcessor::new(initial_data);
    let processed_data = processor.process_data();
    let mutator = DataMutator::new(processor);
    let mutated_data = mutator.mutate_data();
    let analyzer = DataAnalyzer::new(mutator);
    let analysis = analyzer.analyze_data();
    println!("{}", analysis);
}