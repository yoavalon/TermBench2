class LedgerNode
  attr_accessor :data, :next_node

  def initialize(data, next_node = nil)
    @data = data
    @next_node = next_node
  end
end

class LedgerList
  attr_accessor :head

  def initialize
    @head = nil
  end

  def append(data)
    new_node = LedgerNode.new(data)
    if @head.nil?
      @head = new_node
      return
    end
    last_node = @head
    while last_node.next_node
      last_node = last_node.next_node
    end
    last_node.next_node = new_node
  end

  def consensus(node, round_number)
    return if node.nil?
    if round_number.even?
      node.data += 1
    else
      node.data -= 1
    end
    consensus(node.next_node, round_number + 1)
  end
end

def main
  ledger = LedgerList.new
  (0...10).each { |i| ledger.append(i) }
  node = ledger.head
  round_number = 0
  loop do
    ledger.consensus(node, round_number)
    round_number += 1
  end
end

main