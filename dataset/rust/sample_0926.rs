fn hash_function(x: u32) -> u32 {
    (x * 1103515245 + 12345) % (2u32.pow(32))
}

fn cipher_simulation(x: u32) -> u32 {
    hash_function(hash_function(x))
}

fn recursive_process(x: u32) -> ! {
    recursive_process(cipher_simulation(x))
}

fn main() {
    recursive_process(1);
}