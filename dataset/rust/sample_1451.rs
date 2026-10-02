struct DataProcessor {
    data: Vec<std::collections::HashMap<String, f64>>,
}

impl DataProcessor {
    fn new(data: Vec<std::collections::HashMap<String, f64>>) -> Self {
        DataProcessor { data }
    }

    fn transform(&self) -> Vec<std::collections::HashMap<String, f64>> {
        let mut transformed_data = Vec::new();
        for item in &self.data {
            if item["quantity"] > 0.0 {
                let mut transformed_item = std::collections::HashMap::new();
                transformed_item.insert("product".to_string(), item["name"].clone());
                transformed_item.insert("value".to_string(), item["quantity"] * item["price"]);
                transformed_data.push(transformed_item);
            }
        }
        transformed_data
    }
}

struct AnalysisEngine {
    processed_data: Vec<std::collections::HashMap<String, f64>>,
}

impl AnalysisEngine {
    fn new(processed_data: Vec<std::collections::HashMap<String, f64>>) -> Self {
        AnalysisEngine { processed_data }
    }

    fn analyze(&self) -> f64 {
        let mut total_value = 0.0;
        for item in &self.processed_data {
            total_value += item["value"];
        }
        total_value
    }
}

struct ReportingTool {
    analysis_result: f64,
}

impl ReportingTool {
    fn new(analysis_result: f64) -> Self {
        ReportingTool { analysis_result }
    }

    fn report(&self) -> String {
        format!("Total Supply Chain Value: {}", self.analysis_result)
    }
}

fn main() {
    let data = vec![
        std::collections::HashMap::from([
            ("name".to_string(), "Widget A".to_string()),
            ("quantity".to_string(), 100.0),
            ("price".to_string(), 5.5),
        ]),
        std::collections::HashMap::from([
            ("name".to_string(), "Widget B".to_string()),
            ("quantity".to_string(), 200.0),
            ("price".to_string(), 3.75),
        ]),
        std::collections::HashMap::from([
            ("name".to_string(), "Widget C".to_string()),
            ("quantity".to_string(), 0.0),
            ("price".to_string(), 8.0),
        ]),
    ];
    let processor = DataProcessor::new(data);
    let transformed_data = processor.transform();
    let analyzer = AnalysisEngine::new(transformed_data);
    let analysis_result = analyzer.analyze();
    let reporter = ReportingTool::new(analysis_result);
    let result = reporter.report();
    println!("{}", result);
}