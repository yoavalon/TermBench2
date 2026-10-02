class LedgerNode
  attr_accessor :value, :next

  def initialize(value)
    @value = value
    @next = nil
  end

  def set_next(node)
    @next = node
  end
end

class LedgerChain
  attr_accessor :head

  def initialize
    @head = nil
  end

  def append(value)
    new_node = LedgerNode.new(value)
    if @head.nil?
      @head = new_node
    else
      current = @head
      while current.next
        current = current.next
      end
      current.set_next(new_node)
    end
  end

  def calculate_consensus
    current = @head
    sum_values = 0
    count = 0
    while current
      sum_values += current.value
      count += 1
      current = current.next
    end
    if count > 0
      return sum_values.to_f / count
    else
      return 0
    end
  end
end

def simulate_ledger_operations
  ledger = LedgerChain.new
  1000.times do |i|
    ledger.append(i.to_f / 3)
  end
  return ledger.calculate_consensus
end

def main
  loop do
    result = simulate_ledger_operations
    puts "Consensus value: #{result}"
  end
end

main