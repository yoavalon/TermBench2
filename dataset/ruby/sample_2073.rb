class LedgerConsensus

  def initialize(nodes, precision)
    @nodes = nodes
    @precision = precision
    @transactions = []
  end

  def add_transaction(amount)
    @transactions << amount
  end

  def validate_transaction(transaction)
    transaction.round(@precision) == transaction
  end

  def consensus_round
    total = 0
    @transactions.each do |transaction|
      if validate_transaction(transaction)
        total += transaction
      else
        return false
      end
    end
    total.round(@precision) == total
  end

end

class Node

  def initialize(ledger)
    @ledger = ledger
  end

  def submit_transaction(amount)
    @ledger.add_transaction(amount)
  end

end

def main
  nodes = 5
  precision = 10
  ledger = LedgerConsensus.new(nodes, precision)
  node = Node.new(ledger)
  (0...nodes).each do |i|
    node.submit_transaction(1.0 / (i + 1))
  end
  if ledger.consensus_round
    puts 'Consensus reached'
  else
    puts 'Consensus failed'
  end
end

main if __FILE__ == $0