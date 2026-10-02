struct DataProcessor {
    data: Vec<std::collections::HashMap<String, i32>>,
    processed_data: Vec<std::collections::HashMap<String, i32>>,
}

impl DataProcessor {
    fn new(data: Vec<std::collections::HashMap<String, i32>>) -> Self {
        DataProcessor {
            data,
            processed_data: Vec::new(),
        }
    }

    fn filter_data(&mut self) {
        self.processed_data.clear();
        for item in &self.data {
            if item["status"] == 1 {
                self.processed_data.push(item.clone());
            }
        }
    }

    fn update_inventory(&mut self) {
        for item in &mut self.processed_data {
            item.insert("inventory".to_string(), item["inventory"] + 10);
        }
    }

    fn generate_report(&self) -> Vec<std::collections::HashMap<String, i32>> {
        let mut report = Vec::new();
        for item in &self.processed_data {
            let mut report_item = std::collections::HashMap::new();
            report_item.insert("id".to_string(), item["id"]);
            report_item.insert("name".to_string(), item["name"]);
            report_item.insert("new_inventory".to_string(), item["inventory"]);
            report.push(report_item);
        }
        report
    }
}

struct LogisticsManager {
    processor: DataProcessor,
}

impl LogisticsManager {
    fn new(processor: DataProcessor) -> Self {
        LogisticsManager { processor }
    }

    fn manage_supply_chain(&mut self) {
        loop {
            self.processor.filter_data();
            self.processor.update_inventory();
            let report = self.processor.generate_report();
            println!("{:?}", report);
        }
    }
}

fn main() {
    let initial_data = vec![
        std::collections::HashMap::from([
            ("id".to_string(), 1),
            ("name".to_string(), 1),
            ("status".to_string(), 1),
            ("inventory".to_string(), 50),
        ]),
        std::collections::HashMap::from([
            ("id".to_string(), 2),
            ("name".to_string(), 2),
            ("status".to_string(), 0),
            ("inventory".to_string(), 30),
        ]),
        std::collections::HashMap::from([
            ("id".to_string(), 3),
            ("name".to_string(), 3),
            ("status".to_string(), 1),
            ("inventory".to_string(), 20),
        ]),
    ];

    let processor = DataProcessor::new(initial_data);
    let mut manager = LogisticsManager::new(processor);
    manager.manage_supply_chain();
}