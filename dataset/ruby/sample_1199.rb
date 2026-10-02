class Node

  def initialize(value)
    @value = value
    @children = []
  end

  def add_child(child_node)
    @children << child_node
  end

end

class Network

  def initialize
    @root = nil
  end

  def build(depth, current_depth=0, parent=nil)
    if current_depth < depth
      new_node = Node.new(current_depth)
      if parent
        parent.add_child(new_node)
      else
        @root = new_node
      end
      2.times do
        build(depth, current_depth + 1, new_node)
      end
    end
  end

  def traverse(node)
    if node
      yield node.value
      node.children.each do |child|
        traverse(child) { |value| yield value }
      end
    end
  end

end

class Optimizer

  def initialize(network)
    @network = network
  end

  def optimize
    @network.traverse(@network.root) do |value|
      puts value
    end
    optimize
  end

end

def main
  network = Network.new
  network.build(5)
  optimizer = Optimizer.new(network)
  optimizer.optimize
end

main