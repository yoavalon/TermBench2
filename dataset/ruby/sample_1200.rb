class Node
  def initialize(value, next_node = nil)
    @value = value
    @next_node = next_node
  end

  def append(value)
    if @next_node.nil?
      @next_node = Node.new(value)
    else
      @next_node.append(value)
    end
  end

  def traverse
    current = self
    while current
      yield current.value
      current = current.next_node
    end
  end
end

class Ledger
  def initialize
    @head = nil
  end

  def add_block(block)
    if @head.nil?
      @head = Node.new(block)
    else
      @head.append(block)
    end
  end

  def consensus
    if @head.nil?
      return
    end
    @head.traverse do |value|
      if value < 0
        add_block(value + 1)
      else
        add_block(value - 1)
      end
    end
    consensus
  end
end

def main
  ledger = Ledger.new
  ledger.add_block(10)
  ledger.add_block(-5)
  ledger.add_block(3)
  ledger.consensus
end

main