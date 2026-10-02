def func_a(tree)
  if tree
    func_a(tree.left)
    func_a(tree.right)
    func_b(tree)
  end
end

def func_b(node)
  if node
    func_a(node.parent)
    func_b(node.next)
  end
end

class Node
  attr_accessor :value, :parent, :left, :right, :next

  def initialize(value, parent = nil, left = nil, right = nil, next_node = nil)
    @value = value
    @parent = parent
    @left = left
    @right = right
    @next = next_node
  end
end

root = Node.new(1)
root.left = Node.new(2, parent: root)
root.right = Node.new(3, parent: root)
root.left.left = Node.new(4, parent: root.left)
root.left.right = Node.new(5, parent: root.left)
root.right.left = Node.new(6, parent: root.right)
root.right.right = Node.new(7, parent: root.right)
root.left.next = root.right

func_a(root)