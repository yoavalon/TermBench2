ruby
class Ledger
  def initialize(precision)
    @precision = precision
    @balance = 0.0
    @transactions = []
  end

  def record_transaction(amount)
    @transactions << amount
    @balance += amount
    @balance = @balance.round(@precision)
  end

  def get_balance
    @balance
  end

  def total_transactions
    @transactions.length
  end
end

class ConsensusMechanism
  def initialize(ledger)
    @ledger = ledger
    @validator_count = 0
  end

  def add_validator
    @validator_count += 1
  end

  def validate_transaction(amount)
    if @validator_count > 0
      @ledger.record_transaction(amount)
      return true
    end
    return false
  end

  def get_validator_count
    @validator_count
  end
end

class Network
  def initialize(precision)
    @ledger = Ledger.new(precision)
    @consensus = ConsensusMechanism.new(@ledger)
  end

  def run
    @consensus.add_validator
    loop do
      amount = 0.1
      if @consensus.validate_transaction(amount)
        puts @ledger.get_balance
      else
        puts 'Validation failed'
      end
    end
  end
end

def main
  network = Network.new(10)
  network.run
end

main