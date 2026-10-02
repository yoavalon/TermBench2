struct HashSimulator {
    data: Vec<i32>,
    result: Option<i32>,
}

impl HashSimulator {
    fn new(data: Vec<i32>) -> HashSimulator {
        HashSimulator {
            data,
            result: None,
        }
    }

    fn compute_hash(&mut self) {
        if self.data.is_empty() {
            self.result = Some(0);
        } else {
            self.result = Some(self._hash_recursive(&self.data, 0));
        }
    }

    fn _hash_recursive(&self, data: &[i32], index: usize) -> i32 {
        if index == data.len() {
            0
        } else {
            (data[index] + self._hash_recursive(data, index + 1)) % 1000000007
        }
    }
}

struct CipherSimulator {
    key: i32,
    data: Vec<i32>,
    result: Option<Vec<i32>>,
}

impl CipherSimulator {
    fn new(key: i32, data: Vec<i32>) -> CipherSimulator {
        CipherSimulator {
            key,
            data,
            result: None,
        }
    }

    fn encrypt(&mut self) {
        if self.data.is_empty() {
            self.result = Some(vec![]);
        } else {
            self.result = Some(self._encrypt_recursive(&self.data, 0));
        }
    }

    fn _encrypt_recursive(&self, data: &[i32], index: usize) -> Vec<i32> {
        if index == data.len() {
            vec![]
        } else {
            let mut result = self._encrypt_recursive(data, index + 1);
            result.insert(0, (data[index] + self.key) % 256);
            result
        }
    }
}

fn main() {
    let data: Vec<i32> = "Hello, World!".chars().map(|c| c as i32).collect();
    let mut hash_sim = HashSimulator::new(data.clone());
    hash_sim.compute_hash();
    println!("Hash: {:?}", hash_sim.result);
    let key = 42;
    let mut cipher_sim = CipherSimulator::new(key, data);
    cipher_sim.encrypt();
    println!("Encrypted: {:?}", cipher_sim.result);
}