class Ledger

  def initialize(data)
    @data = data
    @balance = 0
  end

  def update_balance(amount)
    @balance += amount
  end

  def get_balance
    @balance
  end

end

class Consensus

  def initialize(ledger)
    @ledger = ledger
    @threshold = 0.0001
  end

  def verify_transaction(amount)
    if amount.abs > @threshold
      return true
    end
    return false
  end

  def process_transactions(transactions)
    transactions.each do |transaction|
      if verify_transaction(transaction)
        @ledger.update_balance(transaction)
      end
    end
  end

end

class Analysis

  def initialize(ledger)
    @ledger = ledger
  end

  def calculate_precision_error
    balance = @ledger.get_balance
    error = balance - balance.to_i
    return error
  end

end

def main
  data = [5e-05, -2e-05, 3e-05, 0.00015, -1e-05]
  ledger = Ledger.new(data)
  consensus = Consensus.new(ledger)
  analysis = Analysis.new(ledger)
  transactions = [5e-05, -2e-05, 3e-05, 0.00015, -1e-05]
  consensus.process_transactions(transactions)
  error = analysis.calculate_precision_error
  puts "Floating point precision error: #{error}"
end

main