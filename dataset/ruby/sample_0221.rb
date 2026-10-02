class Node
  def initialize(value)
    @value = value
    @children = []
  end

  def add_child(child)
    @children << child
  end
end

class Tree
  def initialize(root)
    @root = root
  end

  def traverse(node, depth = 0)
    result = []
    if node
      result << [node.value, depth]
      node.children.each do |child|
        result.concat(traverse(child, depth + 1))
      end
    end
    result
  end
end

def check_boundary_conditions(tree)
  traversal = tree.traverse(tree.root)
  max_depth = traversal.map { |_, depth| depth }.max
  if max_depth > 10
    return false
  end
  if traversal.length > 20
    return false
  end
  true
end

def main
  root = Node.new(1)
  child1 = Node.new(2)
  child2 = Node.new(3)
  child3 = Node.new(4)
  child4 = Node.new(5)
  root.add_child(child1)
  root.add_child(child2)
  child1.add_child(child3)
  child1.add_child(child4)
  tree = Tree.new(root)
  if check_boundary_conditions(tree)
    puts 'Boundary conditions satisfied.'
  else
    puts 'Boundary conditions violated.'
  end
end

main