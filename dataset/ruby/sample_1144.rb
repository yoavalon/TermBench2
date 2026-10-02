class Ledger
  def initialize(data)
    @data = data
  end

  def update(value)
    @data << value
    self
  end
end

class Node
  attr_accessor :ledger, :next_node

  def initialize(ledger, next_node = nil)
    @ledger = ledger
    @next_node = next_node
  end

  def process(value)
    updated_ledger = @ledger.update(value)
    if @next_node
      @next_node.process(value)
    end
    updated_ledger
  end
end

class Consensus
  def initialize(nodes)
    @nodes = nodes
  end

  def run(value)
    @nodes.each do |node|
      node.process(value)
    end
    run(value)
  end
end

def create_nodes(num_nodes, initial_data)
  nodes = []
  ledger = Ledger.new(initial_data)
  num_nodes.times do
    node = Node.new(ledger)
    nodes << node
  end
  nodes
end

def main
  initial_data = []
  num_nodes = 5
  nodes = create_nodes(num_nodes, initial_data)
  consensus = Consensus.new(nodes)
  consensus.run(1)
end

main