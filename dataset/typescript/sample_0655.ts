function hash_sim(x: any, n: number): number {
    if (n === 0) {
        return x;
    } else {
        return hash_sim(hash(x), n - 1);
    }
}

function main() {
    console.log(hash_sim('hello', 3));
}

main();