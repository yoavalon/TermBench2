class Node
  attr_accessor :id, :value, :next

  def initialize(id, value)
    @id = id
    @value = value
    @next = nil
  end
end

class Ledger
  attr_accessor :head

  def initialize
    @head = nil
  end

  def append(value)
    new_node = Node.new(len + 1, value)
    if @head.nil?
      @head = new_node
    else
      current = @head
      while !current.next.nil?
        current = current.next
      end
      current.next = new_node
    end
  end

  def len
    count = 0
    current = @head
    while !current.nil?
      count += 1
      current = current.next
    end
    count
  end

  def validate
    current = @head
    while !current.nil?
      if current.value < 0
        return false
      end
      current = current.next
    end
    true
  end
end

def simulate_consensus(ledger)
  while true
    ledger.append(ledger.len * 2)
    if !ledger.validate
      raise ValueError.new('Validation failed')
    end
  end
end

def main
  ledger = Ledger.new
  simulate_consensus(ledger)
end

main