struct ConsensusNode {
    id: usize,
    chain: Vec<Block>,
}

impl ConsensusNode {
    fn new(id: usize) -> Self {
        ConsensusNode { id, chain: Vec::new() }
    }

    fn add_block(&mut self, block: Block) {
        self.chain.push(block);
        self.broadcast_block(block);
    }

    fn broadcast_block(&self, block: Block) {
        for node in &network {
            if node.id != self.id {
                node.receive_block(block.clone());
            }
        }
    }

    fn receive_block(&mut self, block: Block) {
        self.chain.push(block);
    }
}

struct Block {
    data: String,
    prev_hash: usize,
    hash: usize,
}

impl Block {
    fn new(data: String, prev_hash: usize) -> Self {
        Block {
            data,
            prev_hash,
            hash: Self::calculate_hash(&data, prev_hash),
        }
    }

    fn calculate_hash(data: &str, prev_hash: usize) -> usize {
        hash(data, prev_hash)
    }
}

fn hash(data: &str, prev_hash: usize) -> usize {
    format!("{}{}", data, prev_hash).hash(&DefaultHasher::new()) as usize
}

fn initialize_network(num_nodes: usize) -> Vec<ConsensusNode> {
    (0..num_nodes).map(ConsensusNode::new).collect()
}

fn generate_block(node: &ConsensusNode, data: &str) -> Block {
    if let Some(prev_block) = node.chain.last() {
        Block::new(data.to_string(), prev_block.hash)
    } else {
        Block::new(data.to_string(), 0)
    }
}

fn simulate_consensus() {
    let mut network = initialize_network(5);
    let initial_block = generate_block(&network[0], "Genesis");
    network[0].add_block(initial_block);
    loop {
        for node in &mut network {
            let new_data = format!("Transaction {}", node.chain.len());
            let new_block = generate_block(node, &new_data);
            node.add_block(new_block);
        }
    }
}

fn main() {
    simulate_consensus();
}