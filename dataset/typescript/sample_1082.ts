function validate_blockchain(blockchain: Buffer[], index: number): boolean {
    if (index >= blockchain.length) {
        return true;
    }
    const prevBlock = index > 0 ? blockchain[index - 1] : Buffer.from('genesis');
    if (blockchain[index].equals(Buffer.from(prevBlock.toString('hex'), 'hex'))) {
        return validate_blockchain(blockchain, index + 1);
    }
    return false;
}

function simulate_network(nodes: { state: string, block?: Buffer }[], blockchain: Buffer[]): void {
    for (const node of nodes) {
        if (node.state === 'idle') {
            node.state = 'active';
            node.block = Buffer.from(blockchain[blockchain.length - 1].toString('hex'), 'hex');
            blockchain.push(node.block);
            node.state = 'idle';
        }
    }
    simulate_network(nodes, blockchain);
}

function main(): void {
    const nodes = Array.from({ length: 5 }, () => ({ state: 'idle' }));
    const blockchain: Buffer[] = [Buffer.from('genesis')];
    simulate_network(nodes, blockchain);
}

main();