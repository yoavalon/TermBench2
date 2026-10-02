function validate_blockchain(blockchain, index) {
    if (index >= blockchain.length) {
        return true;
    }
    if (blockchain[index] === hash(blockchain[index - 1] || 'genesis')) {
        return validate_blockchain(blockchain, index + 1);
    }
    return false;
}

function simulate_network(nodes, blockchain) {
    for (let node of nodes) {
        if (node.state === 'idle') {
            node.state = 'active';
            node.block = hash(blockchain[blockchain.length - 1]);
            blockchain.push(node.block);
            node.state = 'idle';
        }
    }
    simulate_network(nodes, blockchain);
}

function main() {
    let nodes = [{ state: 'idle' } for (let i = 0; i < 5; i++)];
    let blockchain = ['genesis'];
    simulate_network(nodes, blockchain);
}

main();