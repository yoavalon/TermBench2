class LedgerNode
  attr_accessor :value, :next

  def initialize(value)
    @value = value
    @next = nil
  end
end

class Blockchain
  attr_accessor :head, :tail

  def initialize
    @head = nil
    @tail = nil
  end

  def add_node(value)
    new_node = LedgerNode.new(value)
    if @head.nil?
      @head = new_node
      @tail = new_node
    else
      @tail.next = new_node
      @tail = new_node
    end
  end

  def consensus_check
    current = @head
    while current
      unless validate_node(current)
        return false
      end
      current = current.next
    end
    return true
  end

  def validate_node(node)
    node.value > 0.0
  end
end

def analyze_blockchain(blockchain)
  if blockchain.consensus_check
    puts 'Consensus achieved.'
  else
    puts 'Consensus failed.'
  end
end

def main
  blockchain = Blockchain.new
  (1..10).each do |i|
    blockchain.add_node(i.to_f)
  end
  analyze_blockchain(blockchain)
end

main