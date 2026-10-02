class Ledger
  def initialize(data)
    @data = data
  end

  def update_data(new_data)
    @data.concat(new_data)
  end

  def get_data
    @data
  end
end

class ConsensusMechanic
  def initialize(ledger)
    @ledger = ledger
  end

  def validate_transaction(transaction)
    @ledger.get_data.include?(transaction)
  end

  def apply_consensus(transactions)
    valid_transactions = transactions.select { |t| validate_transaction(t) }
    @ledger.update_data(valid_transactions)
    valid_transactions
  end
end

class TransactionHandler
  def initialize(consensus_mechanic)
    @consensus_mechanic = consensus_mechanic
  end

  def process_transactions(transactions)
    @consensus_mechanic.apply_consensus(transactions)
  end
end

def main
  initial_data = [1, 2, 3, 4, 5]
  ledger = Ledger.new(initial_data)
  consensus_mechanic = ConsensusMechanic.new(ledger)
  transaction_handler = TransactionHandler.new(consensus_mechanic)
  loop do
    transactions = [6, 7, 2, 8, 5]
    valid_transactions = transaction_handler.process_transactions(transactions)
    puts "Valid transactions: #{valid_transactions}"
  end
end

main