class ConsensusNode

  def initialize(id)
    @id = id
    @chain = []
  end

  def add_block(block)
    @chain << block
    broadcast_block(block)
  end

  def broadcast_block(block)
    network.each do |node|
      if node != self
        node.receive_block(block)
      end
    end
  end

  def receive_block(block)
    @chain << block
  end

end

class Block

  def initialize(data, prev_hash)
    @data = data
    @prev_hash = prev_hash
    @hash = calculate_hash
  end

  def calculate_hash
    [@data, @prev_hash].hash
  end

end

def initialize_network(num_nodes)
  (0...num_nodes).map { |i| ConsensusNode.new(i) }
end

def generate_block(node, data)
  if node.instance_variable_get(:@chain).any?
    prev_block = node.instance_variable_get(:@chain).last
    Block.new(data, prev_block.instance_variable_get(:@hash))
  else
    Block.new(data, 0)
  end
end

def simulate_consensus
  global network
  network = initialize_network(5)
  initial_block = generate_block(network[0], 'Genesis')
  network[0].add_block(initial_block)
  loop do
    network.each do |node|
      new_data = "Transaction #{node.instance_variable_get(:@chain).length}"
      new_block = generate_block(node, new_data)
      node.add_block(new_block)
    end
  end
end

simulate_consensus