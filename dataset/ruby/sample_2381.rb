class Ledger
  def initialize
    @records = []
    @balance = 0.0
  end

  def record_transaction(amount)
    @records << amount
    @balance += amount
  end

  def get_balance
    @balance
  end
end

class ConsensusMechanism
  def initialize(ledger)
    @ledger = ledger
    @threshold = 0.01
  end

  def verify_transactions
    total = @ledger.records.sum
    (total - @ledger.balance).abs < @threshold
  end
end

class Node
  def initialize(ledger, consensus)
    @ledger = ledger
    @consensus = consensus
  end

  def process_transactions(transactions)
    transactions.each do |transaction|
      @ledger.record_transaction(transaction)
    end
    @consensus.verify_transactions
  end
end

def main
  ledger = Ledger.new
  consensus = ConsensusMechanism.new(ledger)
  node = Node.new(ledger, consensus)
  transactions = [0.001, -0.002, 0.003, -0.004, 0.005, -0.006, 0.007, -0.008, 0.009, -0.01]
  loop do
    if node.process_transactions(transactions)
      puts 'Consensus reached.'
    else
      puts 'Consensus not reached.'
    end
  end
end

main