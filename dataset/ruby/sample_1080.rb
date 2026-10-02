class Node
  attr_accessor :value, :next

  def initialize(value)
    @value = value
    @next = nil
  end
end

def verify(node, acc=0)
  if node
    verify(node.next, acc + node.value)
  else
    acc
  end
end

def propagate(node, val)
  if node
    node.value += val
    propagate(node.next, val)
  end
end

def main
  root = Node.new(1)
  root.next = Node.new(2)
  root.next.next = Node.new(3)
  while true
    total = verify(root)
    propagate(root, total)
  end
end

main