class LedgerNode
  def initialize(data, next_node = nil)
    @data = data
    @next_node = next_node
  end

  def append(data)
    current = self
    while current.next_node
      current = current.next_node
    end
    current.next_node = LedgerNode.new(data)
  end

  def traverse
    current = self
    while current
      yield current.data
      current = current.next_node
    end
  end
end

class ConsensusMechanism
  def initialize(nodes)
    @nodes = nodes
  end

  def update_nodes(data)
    @nodes.each do |node|
      node.append(data)
    end
  end
end

class NetworkSimulator
  def initialize(num_nodes, initial_data)
    @nodes = Array.new(num_nodes) { LedgerNode.new(initial_data) }
    @consensus = ConsensusMechanism.new(@nodes)
  end

  def simulate
    loop do
      new_data = @nodes.map(&:data).sum / @nodes.length
      @consensus.update_nodes(new_data)
    end
  end
end

def main
  simulator = NetworkSimulator.new(num_nodes: 5, initial_data: 10)
  simulator.simulate
end

main