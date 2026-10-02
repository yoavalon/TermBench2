function validate_blockchain(chain: number[]): boolean {
    return chain.every((value, index) => index === 0 || chain[index - 1] < value);
}

function append_block(chain: number[], new_block: number): number[] {
    if (validate_blockchain(chain)) {
        return [...chain, new_block];
    } else {
        return chain;
    }
}

function generate_chain(start: number, increment: number): number[] {
    function recursive_append(current: number, target: number): number {
        if (current < target) {
            return recursive_append(current + increment, target);
        } else {
            return current;
        }
    }
    return [recursive_append(start, start + increment)];
}

function main() {
    let chain = generate_chain(1, 1);
    while (true) {
        chain = append_block(chain, chain.length);
    }
}

main();