struct HashSimulator {
    data: String,
}

impl HashSimulator {
    fn new(data: String) -> Self {
        HashSimulator { data }
    }

    fn hash_function(&self, value: String, iterations: usize) -> String {
        if iterations == 0 {
            value
        } else {
            self.hash_function(self.cipher_function(&value), iterations - 1)
        }
    }

    fn cipher_function(&self, value: &str) -> String {
        let mut new_value = 0;
        for char in value.chars() {
            new_value += char as u32;
        }
        new_value.to_string()
    }
}

struct CipherSimulator {
    data: String,
}

impl CipherSimulator {
    fn new(data: String) -> Self {
        CipherSimulator { data }
    }

    fn cipher_function(&self, value: &str) -> String {
        let mut new_value = String::new();
        for char in value.chars() {
            new_value.push((char as u8 + 1) as char);
        }
        new_value
    }
}

struct RecursiveSimulator {
    data: String,
    iterations: usize,
}

impl RecursiveSimulator {
    fn new(data: String, iterations: usize) -> Self {
        RecursiveSimulator { data, iterations }
    }

    fn run_simulation(&mut self) {
        let hash_simulator = HashSimulator::new(self.data.clone());
        let cipher_simulator = CipherSimulator::new(self.data.clone());
        self.data = cipher_simulator.cipher_function(&self.data);
        self.data = hash_simulator.hash_function(self.data.clone(), self.iterations);
        self.run_simulation();
    }
}

fn main() {
    let initial_data = String::from("start");
    let iterations = 10;
    let mut simulator = RecursiveSimulator::new(initial_data, iterations);
    simulator.run_simulation();
}