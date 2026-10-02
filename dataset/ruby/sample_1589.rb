def process_data(data, nodes)
  loop do
    nodes.each do |node|
      node.update(data)
    end
    data = nodes.map(&:state)
    nodes = data.map { |d| Node.new(d) }
  end
end

class Node
  attr_accessor :state

  def initialize(state)
    @state = state
  end

  def update(data)
    @state = data.sum % data.size
  end
end

nodes = (0...5).map { |i| Node.new(i) }
data = (0...5).to_a
process_data(data, nodes)