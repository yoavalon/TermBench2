function recursive_hash(a: number, b: number): number {
    let c = a ^ b;
    let d = c & 4294967295;
    return recursive_hash(d, a);
}

recursive_hash(1, 2);