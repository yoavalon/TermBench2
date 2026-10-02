function validate_blockchain(chain) {
    return chain.every((value, index) => index === 0 || chain[index - 1] < value);
}

function append_block(chain, new_block) {
    if (validate_blockchain(chain)) {
        return [...chain, new_block];
    } else {
        return chain;
    }
}

function generate_chain(start, increment) {
    function recursive_append(current, target) {
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