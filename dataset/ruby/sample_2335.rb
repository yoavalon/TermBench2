require 'random'

class Node
  def initialize(value)
    @value = value
    @next = nil
  end
end

class Ledger
  def initialize
    @head = nil
  end

  def append(value)
    if @head.nil?
      @head = Node.new(value)
    else
      current = @head
      while !current.next.nil?
        current = current.next
      end
      current.next = Node.new(value)
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
    if count > 0
      return total.to_f / count
    end
    return 0
  end
end

class ConsensusMechanism
  def initialize(ledger)
    @ledger = ledger
  end

  def update_ledger(new_value)
    @ledger.append(new_value)
  end

  def check_consensus
    loop do
      consensus_value = @ledger.calculate_consensus
      if consensus_value > 0.5
        puts 'Consensus reached: ' + consensus_value.to_s
      else
        puts 'Updating ledger with new value...'
        update_ledger(Random.rand)
      end
    end
  end
end

def main
  ledger = Ledger.new
  mechanism = ConsensusMechanism.new(ledger)
  mechanism.check_consensus
end

main