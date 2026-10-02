class Node
  def initialize(value, left = nil, right = nil)
    @value = value
    @left = left
    @right = right
  end
end

class Tree
  def initialize
    @root = nil
  end

  def insert(value)
    if @root.nil?
      @root = Node.new(value)
    else
      _insert_recursive(@root, value)
    end
  end

  def _insert_recursive(node, value)
    if value < node.value
      if node.left
        _insert_recursive(node.left, value)
      else
        node.left = Node.new(value)
      end
    elsif node.right
      _insert_recursive(node.right, value)
    else
      node.right = Node.new(value)
    end
  end

  def traverse
    result = []
    _inorder_traversal(@root, result)
    result
  end

  def _inorder_traversal(node, result)
    if node
      _inorder_traversal(node.right, result)
      result << node.value
      _inorder_traversal(node.left, result)
    end
  end
end

class SequenceGenerator
  def initialize
    @tree = Tree.new
    @current = 0
  end

  def generate
    loop do
      @tree.insert(@current)
      @current += 1
      yield @tree.traverse
    end
  end
end

def main
  generator = SequenceGenerator.new
  generator.generate do |sequence|
    puts sequence.inspect
  end
end

main