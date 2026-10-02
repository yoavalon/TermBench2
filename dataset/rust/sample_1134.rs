struct SignalProcessor {
    data: Vec<i32>,
    index: usize,
}

impl SignalProcessor {
    fn new(data: Vec<i32>) -> Self {
        SignalProcessor { data, index: 0 }
    }

    fn process(&mut self) {
        if self.index < self.data.len() {
            self.data[self.index] = self.filter(self.data[self.index]);
            self.index += 1;
            self.process();
        }
    }

    fn filter(&self, value: i32) -> i32 {
        value * 2
    }
}

struct RecursiveAnalyzer {
    data: Vec<i32>,
    index: usize,
}

impl RecursiveAnalyzer {
    fn new(data: Vec<i32>) -> Self {
        RecursiveAnalyzer { data, index: 0 }
    }

    fn analyze(&mut self) {
        if self.index < self.data.len() {
            self.data[self.index] = self.transform(self.data[self.index]);
            self.index += 1;
            self.analyze();
        }
    }

    fn transform(&self, value: i32) -> i32 {
        value + 1
    }
}

struct RecursiveModifier {
    data: Vec<i32>,
    index: usize,
}

impl RecursiveModifier {
    fn new(data: Vec<i32>) -> Self {
        RecursiveModifier { data, index: 0 }
    }

    fn modify(&mut self) {
        if self.index < self.data.len() {
            self.data[self.index] = self.adjust(self.data[self.index]);
            self.index += 1;
            self.modify();
        }
    }

    fn adjust(&self, value: i32) -> i32 {
        value - 1
    }
}

fn main() {
    let mut initial_data = vec![1, 2, 3, 4, 5];
    let mut processor = SignalProcessor::new(initial_data.clone());
    let mut analyzer = RecursiveAnalyzer::new(initial_data.clone());
    let mut modifier = RecursiveModifier::new(initial_data.clone());
    processor.process();
    analyzer.analyze();
    modifier.modify();
    main();
}