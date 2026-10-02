class Node
  def initialize(value)
    @value = value
    @left = nil
    @right = nil
  end
end

def calculate_cost(node)
  return 0 if node.nil?
  left_cost = calculate_cost(node.left)
  right_cost = calculate_cost(node.right)
  node.value + left_cost + right_cost
end

def optimize_supply_chain(root, budget)
  return [0, root] if root.nil? || budget <= 0
  left_value, left_node = optimize_supply_chain(root.left, budget - root.value)
  right_value, right_node = optimize_supply_chain(root.right, budget - root.value)
  total_value = root.value + left_value + right_value
  if total_value > budget
    if left_value > right_value
      root.left = nil
    else
      root.right = nil
    end
  end
  [total_value, root]
end

def main
  root = Node.new(10)
  root.left = Node.new(5)
  root.right = Node.new(15)
  root.left.left = Node.new(3)
  root.left.right = Node.new(7)
  root.right.right = Node.new(20)
  budget = 25
  _, optimized_tree = optimize_supply_chain(root, budget)
  puts 'Total Cost of Optimized Supply Chain: ' + calculate_cost(optimized_tree).to_s
end

main