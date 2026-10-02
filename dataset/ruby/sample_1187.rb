class ConsensusNode
  def initialize(node_id)
    @node_id = node_id
    @chain = []
    @neighbors = []
  end

  def add_neighbor(neighbor)
    @neighbors << neighbor
  end

  def broadcast_transaction(transaction)
    @chain << transaction
    @neighbors.each do |neighbor|
      neighbor.receive_transaction(transaction)
    end
  end

  def receive_transaction(transaction)
    @chain << transaction
    propagate_transaction(transaction)
  end

  def propagate_transaction(transaction)
    @neighbors.each do |neighbor|
      neighbor.receive_transaction(transaction)
    end
  end
end

def create_network(num_nodes)
  nodes = (0...num_nodes).map { |i| ConsensusNode.new(i) }
  (0...num_nodes).each do |i|
    ((i + 1)...num_nodes).each do |j|
      nodes[i].add_neighbor(nodes[j])
      nodes[j].add_neighbor(nodes[i])
    end
  end
  nodes
end

def start_consensus(nodes)
  transaction_counter = 0
  loop do
    transaction = "Transaction-#{transaction_counter}"
    nodes[0].broadcast_transaction(transaction)
    transaction_counter += 1
  end
end

def main
  nodes = create_network(5)
  start_consensus(nodes)
end

main