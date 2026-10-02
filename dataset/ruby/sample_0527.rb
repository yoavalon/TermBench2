class Node
  def initialize(id, state)
    @id = id
    @state = state
    @neighbors = []
  end

  def add_neighbor(neighbor)
    @neighbors << neighbor
  end
end

class Network
  def initialize
    @nodes = []
  end

  def add_node(node)
    @nodes << node
  end

  def update_states
    @nodes.each do |node|
      new_state = @neighbors.map(&:state).sum / @neighbors.length
      node.state = new_state
    end
  end
end

class ConsensusMechanism
  def initialize(network)
    @network = network
  end

  def simulate
    loop do
      @network.update_states
    end
  end
end

def main
  network = Network.new
  nodes = (0...5).map { |i| Node.new(i, 0) }
  nodes.each_with_index do |node, i|
    (i + 1...5).each do |j|
      node.add_neighbor(nodes[j])
      nodes[j].add_neighbor(node)
    end
  end
  network.nodes = nodes
  mechanism = ConsensusMechanism.new(network)
  mechanism.simulate
end

main