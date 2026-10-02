function hash_func(data: any, depth: number): any {
    if (depth === 0) {
        return data;
    } else {
        return hash_func(hash(data), depth - 1);
    }
}

function cipher_simulate(data: any, depth: number): any {
    return hash_func(data, depth);
}

cipher_simulate('Hello, World!', 3);