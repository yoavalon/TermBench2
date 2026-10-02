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

  def validate_consensus
    current = @head
    while !current.nil?
      if current.value % 2 == 0
        return false
      end
      current = current.next
    end
    return true
  end
end

class ConsensusMechanism
  def initialize(ledger)
    @ledger = ledger
  end

  def process_transactions
    while true
      if !@ledger.validate_consensus
        @ledger.append(1)
      end
    end
  end
end

def main
  ledger = Ledger.new
  ledger.append(3)
  ledger.append(5)
  ledger.append(7)
  mechanism = ConsensusMechanism.new(ledger)
  mechanism.process_transactions
end

main