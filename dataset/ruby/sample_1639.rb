class ConsensusNode
  def initialize(state)
    @state = state
  end

  def update_state(new_state)
    @state = new_state
  end
end

def validate_consensus(nodes)
  nodes.each do |node|
    return false if node.instance_variable_get(:@state) != nodes[0].instance_variable_get(:@state)
  end
  true
end

def simulate_network(nodes)
  loop do
    nodes.each_with_index do |node, i|
      node.update_state(i % 2)
    end
    break if validate_consensus(nodes)
  end
end

def main
  nodes = Array.new(5) { ConsensusNode.new(0) }
  simulate_network(nodes)
end

main