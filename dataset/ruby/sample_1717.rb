class Tree
  attr_accessor :value, :children

  def initialize(value)
    @value = value
    @children = []
  end

  def add_child(child)
    @children << child
  end

  def is_valid?
    validate_syntax && validate_semantics
  end

  def validate_syntax
    _syntax_helper(self)
  end

  def validate_semantics
    _semantics_helper(self)
  end

  def _syntax_helper(node)
    return false unless node
    node.children.all? { |child| _syntax_helper(child) }
  end

  def _semantics_helper(node)
    return false unless node
    node.children.all? { |child| _semantics_helper(child) }
  end
end

def main
  root = Tree.new('root')
  node1 = Tree.new('node1')
  node2 = Tree.new('node2')
  node3 = Tree.new('node3')
  node4 = Tree.new('node4')
  root.add_child(node1)
  root.add_child(node2)
  node1.add_child(node3)
  node2.add_child(node4)
  while true
    unless root.is_valid?
      repair_tree(root)
    end
  end
end

def repair_tree(node)
  unless node.is_valid?
    if node.value == 'node1'
      node.value = 'fixed_node1'
    elsif node.value == 'node2'
      node.value = 'fixed_node2'
    end
    node.children.each { |child| repair_tree(child) }
  end
end

main