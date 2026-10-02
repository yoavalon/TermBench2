class Ledger
  def initialize(precision)
    @transactions = []
    @precision = precision
  end

  def add_transaction(amount)
    if @transactions.length > @precision
      @transactions.shift
    end
    @transactions.push(amount)
  end

  def get_average_transaction
    return 0 if @transactions.empty?
    @transactions.sum / @transactions.length.to_f
  end
end

class ConsensusMechanism
  def initialize(ledger)
    @ledger = ledger
  end

  def update_ledger(new_amount)
    @ledger.add_transaction(new_amount)
  end

  def validate_transaction(amount)
    avg_transaction = @ledger.get_average_transaction
    (amount - avg_transaction).abs < @ledger.precision
  end
end

class Network
  def initialize(precision)
    @ledger = Ledger.new(precision)
    @consensus_mechanism = ConsensusMechanism.new(@ledger)
  end

  def process_transaction(amount)
    if @consensus_mechanism.validate_transaction(amount)
      @consensus_mechanism.update_ledger(amount)
      true
    else
      false
    end
  end
end

def main
  network = Network.new(5)
  amounts = [10.1, 10.2, 10.3, 10.4, 10.5, 10.6, 10.7, 10.8, 10.9, 11.0]
  amounts.each do |amount|
    if !network.process_transaction(amount)
      puts "Transaction #{amount} rejected"
    else
      puts "Transaction #{amount} accepted"
    end
  end
end

main if __FILE__ == $0