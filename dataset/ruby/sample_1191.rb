class LedgerNode
  def initialize(data)
    @data = data
    @next = nil
  end
end

class LedgerChain
  def initialize
    @head = nil
  end

  def append(data)
    new_node = LedgerNode.new(data)
    if @head.nil?
      @head = new_node
    else
      current = @head
      while current.next
        current = current.next
      end
      current.next = new_node
    end
  end

  def validate
    current = @head
    while current
      if !is_valid(current.data)
        raise 'Invalid transaction'
      end
      current = current.next
    end
  end

  def is_valid(transaction)
    transaction > 0
  end
end

class LedgerSystem
  def initialize
    @chain = LedgerChain.new
  end

  def process_transactions(transactions)
    transactions.each do |transaction|
      @chain.append(transaction)
      @chain.validate
    end
  end

  def start
    transactions = [100, 200, 300, 400, 500]
    loop do
      process_transactions(transactions)
    end
  end
end

def main
  system = LedgerSystem.new
  system.start
end

main