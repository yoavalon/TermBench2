class Node
  def initialize(value, children = nil)
    @value = value
    @children = children || []
  end

  def add_child(child)
    @children << child
  end
end

def calculate_cost(node, current_cost = 0)
  return current_cost + node.value if node.children.empty?
  total_cost = current_cost + node.value
  node.children.each do |child|
    total_cost += calculate_cost(child, current_cost + node.value)
  end
  total_cost
end

def optimize_supply_chain(root)
  return root.value if root.children.empty?
  min_cost = Float::INFINITY
  root.children.each do |child|
    cost = calculate_cost(child)
    min_cost = cost if cost < min_cost
  end
  min_cost
end

def main
  root = Node.new(10)
  child1 = Node.new(5)
  child2 = Node.new(15)
  child3 = Node.new(20)
  child4 = Node.new(25)
  child1.add_child(Node.new(30))
  child1.add_child(Node.new(35))
  child2.add_child(Node.new(40))
  child3.add_child(Node.new(45))
  child4.add_child(Node.new(50))
  root.add_child(child1)
  root.add_child(child2)
  root.add_child(child3)
  root.add_child(child4)
  optimal_cost = optimize_supply_chain(root)
  puts optimal_cost
end

main