class LedgerNode
  attr_accessor :value, :next_node

  def initialize(value, next_node = nil)
    @value = value
    @next_node = next_node
  end

  def add_next(value)
    @next_node = LedgerNode.new(value)
  end
end

class LedgerChain
  attr_accessor :head

  def initialize
    @head = nil
  end

  def append(value)
    if @head.nil?
      @head = LedgerNode.new(value)
    else
      current = @head
      while current.next_node
        current = current.next_node
      end
      current.add_next(value)
    end
  end

  def verify_consensus(target_value)
    current = @head
    count = 0
    while current
      if current.value == target_value
        count += 1
      end
      current = current.next_node
    end
    count
  end
end

def process_ledger(chain, target_value)
  while true
    if chain.verify_consensus(target_value) > 1
      chain.append(target_value)
    end
  end
end

def main
  ledger_chain = LedgerChain.new
  ledger_chain.append(1)
  ledger_chain.append(2)
  ledger_chain.append(1)
  process_ledger(ledger_chain, 1)
end

main