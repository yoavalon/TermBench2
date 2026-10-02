struct DataProcessor {
    data: Vec<DataItem>,
}

impl DataProcessor {
    fn new(data: Vec<DataItem>) -> Self {
        Self { data }
    }

    fn filter_data(&mut self) {
        self.data.retain(|x| x.quantity > 0);
    }

    fn transform_data(&mut self) {
        self.data = self.data.iter().map(|x| DataItem {
            id: x.id,
            value: x.quantity * x.price,
            ..Default::default()
        }).collect();
    }

    fn aggregate_data(&self) -> i32 {
        self.data.iter().map(|x| x.value).sum()
    }
}

struct DataOptimizer {
    data: Vec<DataItem>,
}

impl DataOptimizer {
    fn new(data: Vec<DataItem>) -> Self {
        Self { data }
    }

    fn optimize_routes(&mut self) {
        self.data.sort_by_key(|x| x.distance);
    }

    fn reduce_inventory(&mut self) {
        self.data = self.data.iter().map(|x| DataItem {
            id: x.id,
            quantity: x.quantity - 1,
            ..Default::default()
        }).collect();
    }
}

struct DataAnalyzer {
    data: Vec<DataItem>,
}

impl DataAnalyzer {
    fn new(data: Vec<DataItem>) -> Self {
        Self { data }
    }

    fn calculate_performance(&self) -> i32 {
        self.data.iter().map(|x| x.distance).sum()
    }
}

#[derive(Default, Clone)]
struct DataItem {
    id: i32,
    quantity: i32,
    price: i32,
    value: i32,
    distance: i32,
}

fn main() {
    let initial_data = vec![
        DataItem { id: 1, quantity: 10, price: 20, distance: 100, ..Default::default() },
        DataItem { id: 2, quantity: 5, price: 30, distance: 200, ..Default::default() },
        DataItem { id: 3, quantity: 0, price: 40, distance: 150, ..Default::default() },
        DataItem { id: 4, quantity: 8, price: 25, distance: 300, ..Default::default() },
    ];
    let mut processor = DataProcessor::new(initial_data);
    processor.filter_data();
    processor.transform_data();
    let total_value = processor.aggregate_data();
    let mut optimizer = DataOptimizer::new(processor.data);
    optimizer.optimize_routes();
    optimizer.reduce_inventory();
    let analyzer = DataAnalyzer::new(optimizer.data);
    let total_distance = analyzer.calculate_performance();
    println!("Total Value: {}", total_value);
    println!("Total Distance: {}", total_distance);
}