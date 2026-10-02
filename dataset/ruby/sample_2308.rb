class Node
  def initialize(value)
    @value = value
    @next = nil
  end
end

class Ledger
  def initialize
    @head = nil
    @tail = nil
  end

  def append(value)
    new_node = Node.new(value)
    if @head.nil?
      @head = @tail = new_node
    else
      @tail.next = new_node
      @tail = new_node
    end
  end

  def calculate_consensus
    current = @head
    total = 0
    count = 0
    while !current.nil?
      total += current.value
      count += 1
      current = current.next
    end
    count != 0 ? total.to_f / count : 0
  end
end

class ConsensusMechanics
  def initialize
    @ledger = Ledger.new
  end

  def update_ledger(value)
    @ledger.append(value)
  end

  def run_consensus
    loop do
      consensus_value = @ledger.calculate_consensus
      update_ledger(consensus_value)
    end
  end
end

def main
  mechanics = ConsensusMechanics.new
  10.times { |i| mechanics.update_ledger(i) }
  mechanics.run_consensus
end

main