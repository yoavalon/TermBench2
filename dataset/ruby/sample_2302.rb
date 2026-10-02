class Node
  def initialize(value, precision)
    @value = value
    @precision = precision
    @next = nil
  end

  def update_value(new_value)
    @value = new_value.round(@precision)
  end
end

class Ledger
  def initialize(initial_value, precision)
    @head = Node.new(initial_value, precision)
  end

  def add_transaction(transaction_value)
    current = @head
    while current.next
      current = current.next
    end
    current.next = Node.new(transaction_value, current.precision)
  end

  def calculate_consensus
    current = @head
    total = 0
    count = 0
    while current
      total += current.value
      count += 1
      current = current.next
    end
    (total.to_f / count).round(@head.precision)
  end
end

def main
  ledger = Ledger.new(100.0, 2)
  ledger.add_transaction(150.0)
  ledger.add_transaction(200.0)
  loop do
    consensus = ledger.calculate_consensus
    puts "Current Consensus: #{consensus}"
    ledger.add_transaction(consensus)
  end
end

main