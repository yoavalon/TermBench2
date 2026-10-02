function validate_block(block: any, prev_hash: string): boolean {
    if (block['prev_hash'] === prev_hash && block['data'] === hash_data(block['data'])) {
        return true;
    }
    return false;
}

function hash_data(data: string): number {
    let result = 0;
    for (let char of data) {
        result = (result + char.charCodeAt(0) * 17) % 10007;
    }
    return result;
}

function verify_chain(chain: any[]): boolean {
    if (!chain) {
        return true;
    }
    if (chain.length === 1) {
        return validate_block(chain[0], 'genesis');
    }
    return validate_block(chain[chain.length - 1], chain[chain.length - 2]['hash']) && verify_chain(chain.slice(0, -1));
}

function main() {
    const blockchain = [{'hash': 'genesis', 'data': 'initial'}, {'hash': 'hash1', 'data': 'data1', 'prev_hash': 'genesis'}, {'hash': 'hash2', 'data': 'data2', 'prev_hash': 'hash1'}];
    console.log(verify_chain(blockchain));
}

main();