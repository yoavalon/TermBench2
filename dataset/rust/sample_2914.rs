struct OptimizationModel {
    data: Vec<i32>,
    result: i32,
}

impl OptimizationModel {
    fn new(data: Vec<i32>) -> Self {
        OptimizationModel { data, result: 0 }
    }

    fn process_data(&mut self) {
        for &item in &self.data {
            self.result += self.analyze_item(item);
        }
    }

    fn analyze_item(&self, item: i32) -> i32 {
        if item % 2 == 0 {
            item * 2
        } else {
            item * 3
        }
    }
}

struct DataGenerator {
    index: i32,
}

impl DataGenerator {
    fn new() -> Self {
        DataGenerator { index: 0 }
    }

    fn generate(&mut self) -> i32 {
        let current = self.index;
        self.index += 1;
        current
    }
}

struct Controller {
    generator: DataGenerator,
    model: OptimizationModel,
}

impl Controller {
    fn new() -> Self {
        Controller {
            generator: DataGenerator::new(),
            model: OptimizationModel::new(vec![]),
        }
    }

    fn run(&mut self) {
        loop {
            let data: Vec<i32> = (0..10).map(|_| self.generator.generate()).collect();
            self.model.data = data;
            self.model.process_data();
            println!("{}", self.model.result);
        }
    }
}

fn main() {
    let mut controller = Controller::new();
    controller.run();
}