class LedgerNode
  attr_accessor :data, :next

  def initialize(data)
    @data = data
    @next = nil
  end
end

class Blockchain
  attr_accessor :head

  def initialize
    @head = nil
  end

  def add_block(data)
    new_node = LedgerNode.new(data)
    if @head.nil?
      @head = new_node
    else
      current = @head
      while current.next
        current = current.next
      end
      current.next = new_node
    end
  end

  def verify_chain
    current = @head
    while current
      unless validate_data(current.data)
        return false
      end
      current = current.next
    end
    return true
  end

  def validate_data(data)
    data.is_a?(Float) && data > 0.0 && data < 1000.0
  end
end

def main
  blockchain = Blockchain.new
  10.times do |i|
    blockchain.add_block(i.to_f / 3.0)
  end
  puts blockchain.verify_chain
end

main