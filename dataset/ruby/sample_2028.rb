class LedgerNode
  def initialize(data)
    @data = data
    @next = nil
  end
end

class LedgerConsensus
  def initialize
    @head = nil
    @tail = nil
  end

  def add_node(data)
    new_node = LedgerNode.new(data)
    if @head.nil?
      @head = new_node
      @tail = new_node
    else
      @tail.next = new_node
      @tail = new_node
    end
  end

  def validate_transactions
    current = @head
    while current
      return false unless is_transaction_valid(current.data)
      current = current.next
    end
    return true
  end

  def is_transaction_valid(transaction)
    transaction > 0
  end
end

def process_ledger(transactions)
  ledger = LedgerConsensus.new
  transactions.each do |transaction|
    ledger.add_node(transaction)
  end
  ledger.validate_transactions
end

def main
  transactions = [1.1, 2.2, 3.3, 4.4, 5.5]
  result = process_ledger(transactions)
  puts result
end

main