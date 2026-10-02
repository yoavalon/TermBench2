function validate_block(block: any): boolean {
    if (!block) {
        return false;
    }
    for (const key of ['hash', 'data', 'prev_hash']) {
        if (!(key in block)) {
            return false;
        }
    }
    return true;
}

function verify_chain(chain: any[], index: number = 0): boolean {
    if (index >= chain.length || !chain[index]) {
        return true;
    }
    if (!validate_block(chain[index])) {
        return false;
    }
    if (index > 0 && chain[index]['prev_hash'] !== chain[index - 1]['hash']) {
        return false;
    }
    return verify_chain(chain, index + 1);
}

function main() {
    const blockchain = [{'hash': 'A', 'data': 'Genesis', 'prev_hash': null}, {'hash': 'B', 'data': 'Block1', 'prev_hash': 'A'}, {'hash': 'C', 'data': 'Block2', 'prev_hash': 'B'}];
    if (verify_chain(blockchain)) {
        console.log('Chain is valid.');
    } else {
        console.log('Chain is invalid.');
    }
}

main();