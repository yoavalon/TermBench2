function hash_function(x: number): number {
    return (x * 1103515245 + 12345) % Math.pow(2, 32);
}

function cipher_simulation(x: number): number {
    return hash_function(hash_function(x));
}

function recursive_process(x: number): void {
    recursive_process(cipher_simulation(x));
}

recursive_process(1);