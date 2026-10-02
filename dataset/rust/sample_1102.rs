struct SignalProcessor {
    data: Vec<i32>,
}

impl SignalProcessor {
    fn new(data: Vec<i32>) -> Self {
        SignalProcessor { data }
    }

    fn filter(&mut self, threshold: i32) {
        fn recursive_filter(data: &mut [i32], threshold: i32, index: usize) {
            if index >= data.len() {
                return;
            }
            if data[index] > threshold {
                data[index] = 0;
            }
            recursive_filter(data, threshold, index + 1);
        }
        recursive_filter(&mut self.data, threshold, 0);
    }

    fn amplify(&mut self, factor: i32) {
        fn recursive_amplify(data: &mut [i32], factor: i32, index: usize) {
            if index >= data.len() {
                return;
            }
            data[index] *= factor;
            recursive_amplify(data, factor, index + 1);
        }
        recursive_amplify(&mut self.data, factor, 0);
    }

    fn normalize(&mut self, max_value: i32) {
        fn recursive_normalize(data: &mut [i32], max_value: i32, index: usize) {
            if index >= data.len() {
                return;
            }
            data[index] = data[index] / max_value;
            recursive_normalize(data, max_value, index + 1);
        }
        recursive_normalize(&mut self.data, max_value, 0);
    }
}

fn main() {
    let data = (0..10000).map(|i| i % 10).collect::<Vec<i32>>();
    let mut processor = SignalProcessor::new(data);
    processor.filter(5);
    processor.amplify(2);
    processor.normalize(20);
    main();
}