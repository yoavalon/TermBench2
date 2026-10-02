class Node
  attr_accessor :value, :left, :right

  def initialize(value)
    @value = value
    @left = nil
    @right = nil
  end
end

class Ledger
  attr_accessor :root

  def initialize
    @root = nil
  end

  def insert(value)
    if @root.nil?
      @root = Node.new(value)
    else
      _insert(@root, value)
    end
  end

  def _insert(node, value)
    if value < node.value
      if node.left
        _insert(node.left, value)
      else
        node.left = Node.new(value)
      end
    elsif node.right
      _insert(node.right, value)
    else
      node.right = Node.new(value)
    end
  end
end

class Consensus
  attr_accessor :ledger

  def initialize(ledger)
    @ledger = ledger
  end

  def validate
    _validate(@ledger.root)
  end

  def _validate(node)
    return true if node.nil?
    return false if node.left && node.left.value > node.value
    return false if node.right && node.right.value < node.value
    _validate(node.left) && _validate(node.right)
  end
end

def main
  ledger = Ledger.new
  100.times do |i|
    ledger.insert(i)
  end
  consensus = Consensus.new(ledger)
  puts consensus.validate
end

main if __FILE__ == $0