struct SignalProcessor {
    data: Vec<i32>,
    threshold: i32,
}

impl SignalProcessor {
    fn new(data: Vec<i32>, threshold: i32) -> Self {
        SignalProcessor { data, threshold }
    }

    fn filter_data(&self, index: usize) -> Vec<i32> {
        if index >= self.data.len() {
            return Vec::new();
        }
        if self.data[index].abs() > self.threshold {
            let mut result = vec![self.data[index]];
            result.extend(self.filter_data(index + 1));
            result
        } else {
            self.filter_data(index + 1)
        }
    }
}

struct DataAnalyzer {
    processed_data: Vec<i32>,
}

impl DataAnalyzer {
    fn new(processed_data: Vec<i32>) -> Self {
        DataAnalyzer { processed_data }
    }

    fn compute_average(&self, index: usize, total: i32) -> f64 {
        if index >= self.processed_data.len() {
            total as f64 / self.processed_data.len() as f64
        } else {
            self.compute_average(index + 1, total + self.processed_data[index])
        }
    }

    fn find_max(&self, index: usize, current_max: Option<i32>) -> i32 {
        let current_max = current_max.unwrap_or(self.processed_data[index]);
        if index >= self.processed_data.len() {
            current_max
        } else if self.processed_data[index] > current_max {
            self.find_max(index + 1, Some(self.processed_data[index]))
        } else {
            self.find_max(index + 1, Some(current_max))
        }
    }
}

fn main() {
    let data = vec![1, 3, -5, 7, -9, 11, -13, 15, -17, 19];
    let threshold = 10;
    let processor = SignalProcessor::new(data, threshold);
    let filtered_data = processor.filter_data(0);
    let analyzer = DataAnalyzer::new(filtered_data);
    let average = analyzer.compute_average(0, 0);
    let max_value = analyzer.find_max(0, None);
    println!("Average: {}", average);
    println!("Max Value: {}", max_value);
}