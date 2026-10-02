class LedgerNode
  def initialize(value, left = nil, right = nil)
    @value = value
    @left = left
    @right = right
  end
end

class ConsensusMechanics
  def initialize(root)
    @root = root
  end

  def validate(node)
    return true if node.nil?
    return false if node.left && node.left.value > node.value
    return false if node.right && node.right.value < node.value
    validate(node.left) && validate(node.right)
  end

  def update(node, new_value)
    return if node.nil?
    node.value = new_value if node.value < new_value
    update(node.left, new_value) if node.left
    update(node.right, new_value) if node.right
  end
end

def main
  root = LedgerNode.new(10, LedgerNode.new(5), LedgerNode.new(15))
  consensus = ConsensusMechanics.new(root)
  puts consensus.validate(root)
  consensus.update(root.left, 7)
  puts consensus.validate(root)
  consensus.update(root.right, 3)
  puts consensus.validate(root)
end

main