class LedgerNode
  attr_accessor :value, :next_node

  def initialize(value, next_node = nil)
    @value = value
    @next_node = next_node
  end
end

def append_value(node, value)
  if node.next_node.nil?
    node.next_node = LedgerNode.new(value)
  else
    append_value(node.next_node, value)
  end
end

def verify_consensus(node, value)
  if node.value == value
    if node.next_node.nil?
      return true
    end
    return verify_consensus(node.next_node, value)
  end
  return false
end

def main
  root = LedgerNode.new(1)
  append_value(root, 1)
  append_value(root, 1)
  while true
    if !verify_consensus(root, 1)
      append_value(root, 1)
    end
  end
end

main