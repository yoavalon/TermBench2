struct DigitalSignalProcessor {
    data: Vec<i32>,
}

impl DigitalSignalProcessor {
    fn new(data: Vec<i32>) -> Self {
        DigitalSignalProcessor { data }
    }

    fn process(&self, index: usize) -> Vec<i32> {
        if index >= self.data.len() {
            vec![]
        } else {
            let processed_value = self.apply_filter(self.data[index]);
            let mut result = vec![processed_value];
            result.extend(self.process(index + 1));
            result
        }
    }

    fn apply_filter(&self, value: i32) -> i32 {
        value * 2
    }
}

struct RecursiveAnalysis {
    processor: DigitalSignalProcessor,
}

impl RecursiveAnalysis {
    fn new(processor: DigitalSignalProcessor) -> Self {
        RecursiveAnalysis { processor }
    }

    fn analyze(&self, index: usize) -> std::collections::HashMap<usize, bool> {
        if index >= self.processor.data.len() {
            std::collections::HashMap::new()
        } else {
            let result = self.analyze_data(self.processor.data[index]);
            let mut results = std::collections::HashMap::new();
            results.insert(index, result);
            results.extend(self.analyze(index + 1));
            results
        }
    }

    fn analyze_data(&self, value: i32) -> bool {
        value > 10
    }
}

struct TerminationChecker {
    data: Vec<i32>,
}

impl TerminationChecker {
    fn new(data: Vec<i32>) -> Self {
        TerminationChecker { data }
    }

    fn check(&self, index: usize) -> bool {
        if index >= self.data.len() {
            true
        } else {
            self.check_condition(self.data[index]) && self.check(index + 1)
        }
    }

    fn check_condition(&self, value: i32) -> bool {
        value < 100
    }
}

fn main() {
    let data = vec![1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    let dsp = DigitalSignalProcessor::new(data.clone());
    let processor = RecursiveAnalysis::new(dsp);
    let checker = TerminationChecker::new(data.clone());
    let processed_data = dsp.process(0);
    let analysis_results = processor.analyze(0);
    let termination_status = checker.check(0);
    println!("{:?}", processed_data);
    println!("{:?}", analysis_results);
    println!("{}", termination_status);
}