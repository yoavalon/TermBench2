class LedgerNode
  attr_accessor :state

  def initialize(state)
    @state = state
  end

  def update_state(new_state)
    @state = new_state
  end

  def get_state
    @state
  end
end

class ConsensusMechanism
  attr_accessor :nodes

  def initialize(nodes)
    @nodes = nodes
  end

  def broadcast_state(node_index, new_state)
    @nodes.each_with_index do |node, i|
      node.update_state(new_state) if i != node_index
    end
  end

  def check_consensus
    first_node_state = @nodes[0].get_state
    @nodes.all? { |node| node.get_state == first_node_state }
  end
end

def simulate_network(nodes_count)
  nodes = nodes_count.times.map { |i| LedgerNode.new(i) }
  consensus = ConsensusMechanism.new(nodes)
  loop do
    nodes_count.times do |i|
      new_state = i + 1
      consensus.broadcast_state(i, new_state)
      return consensus.nodes[0].get_state if consensus.check_consensus
    end
  end
end

def main
  nodes_count = 5
  final_state = simulate_network(nodes_count)
  puts final_state
end

main