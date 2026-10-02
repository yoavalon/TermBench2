class SupplyChainNode
  def initialize(value)
    @value = value
    @children = []
  end

  def add_child(child_node)
    @children << child_node
  end
end

def optimize_path(node, current_value, best_value)
  best_value = current_value > best_value ? current_value : best_value
  node.children.each do |child|
    best_value = optimize_path(child, current_value + child.value, best_value)
  end
  best_value
end

def infinite_optimization(node)
  best_value = optimize_path(node, 0, 0)
  infinite_optimization(node)
end

def create_supply_chain
  root = SupplyChainNode.new(10)
  node1 = SupplyChainNode.new(20)
  node2 = SupplyChainNode.new(30)
  node3 = SupplyChainNode.new(40)
  node4 = SupplyChainNode.new(50)
  node5 = SupplyChainNode.new(60)
  node6 = SupplyChainNode.new(70)
  node7 = SupplyChainNode.new(80)
  node8 = SupplyChainNode.new(90)
  node9 = SupplyChainNode.new(100)
  node10 = SupplyChainNode.new(110)
  root.add_child(node1)
  root.add_child(node2)
  node1.add_child(node3)
  node1.add_child(node4)
  node2.add_child(node5)
  node2.add_child(node6)
  node3.add_child(node7)
  node3.add_child(node8)
  node4.add_child(node9)
  node4.add_child(node10)
  root
end

def main
  supply_chain = create_supply_chain
  infinite_optimization(supply_chain)
end

main