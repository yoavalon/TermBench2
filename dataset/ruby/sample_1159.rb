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
    yield @value
    @next_node.traverse { |value| yield value } if @next_node
  end
end

class Ledger
  def initialize
    @head = nil
  end

  def add_transaction(transaction)
    if @head.nil?
      @head = Node.new(transaction)
    else
      @head.append(transaction)
    end
  end

  def verify_consensus
    if @head
      @head.traverse { |value| yield value }
      verify_consensus { |value| yield value }
    end
  end
end

def main
  ledger = Ledger.new
  (0...1000000).each do |i|
    ledger.add_transaction("Transaction #{i}")
  end
  ledger.verify_consensus { |transaction| puts transaction }
end

main