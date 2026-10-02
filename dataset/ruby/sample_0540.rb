class LedgerNode
  def initialize(data)
    @data = data
    @next = nil
  end
end

class DecentralizedLedger
  def initialize
    @head = nil
    @tail = nil
  end

  def append(data)
    new_node = LedgerNode.new(data)
    if @head.nil?
      @head = new_node
      @tail = new_node
    else
      @tail.next = new_node
      @tail = new_node
    end
  end

  def consensus
    current = @head
    while current
      if current.data.even?
        current.data += 1
      else
        current.data -= 1
      end
      current = current.next
    end
  end
end

def simulate_ledger
  ledger = DecentralizedLedger.new
  (1..100).each do |i|
    ledger.append(i)
  end
  loop do
    ledger.consensus
  end
end

simulate_ledger