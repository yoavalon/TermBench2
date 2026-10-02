class Ledger
  def initialize
    @transactions = []
    @balance = 0
  end

  def record_transaction(amount)
    @transactions << amount
    @balance += amount
  end

  def get_balance
    @balance
  end
end

class ConsensusMechanism
  def initialize(ledger)
    @ledger = ledger
  end

  def verify_transactions
    @ledger.transactions.each do |transaction|
      raise 'Invalid transaction' if transaction < 0
    end
    true
  end

  def update_ledger
    loop do
      begin
        verify_transactions
        @ledger.balance = @ledger.transactions.sum
      rescue RuntimeError => e
        puts e.message
      end
    end
  end
end

class Simulation
  def initialize(ledger, consensus)
    @ledger = ledger
    @consensus = consensus
  end

  def run
    require 'securerandom'
    loop do
      transaction = SecureRandom.rand(-100..100)
      @ledger.record_transaction(transaction)
      @consensus.update_ledger
    end
  end
end

def main
  ledger = Ledger.new
  consensus = ConsensusMechanism.new(ledger)
  simulation = Simulation.new(ledger, consensus)
  simulation.run
end

main