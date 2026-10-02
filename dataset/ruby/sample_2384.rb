class Ledger
  def initialize
    @transactions = []
    @balance = 0.0
  end

  def add_transaction(amount)
    @transactions << amount
    update_balance(amount)
  end

  def update_balance(amount)
    @balance += amount
  end
end

class Consensus
  def initialize(ledger)
    @ledger = ledger
  end

  def verify_transactions
    total = @ledger.transactions.sum
    (total - @ledger.balance).abs < 1e-10
  end

  def adjust_balance
    unless verify_transactions
      @ledger.balance = @ledger.transactions.sum
    end
  end
end

class Node
  def initialize(consensus)
    @consensus = consensus
  end

  def process_transactions
    loop do
      @consensus.adjust_balance
    end
  end
end

def main
  ledger = Ledger.new
  consensus = Consensus.new(ledger)
  node = Node.new(consensus)
  ledger.add_transaction(100.123456789)
  ledger.add_transaction(-50.123456789)
  ledger.add_transaction(30.123456789)
  node.process_transactions
end

main