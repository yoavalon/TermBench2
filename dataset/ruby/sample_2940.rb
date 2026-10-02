class SequenceGenerator
  def initialize(a, b)
    @a = a
    @b = b
    @current = 0
  end

  def next_value
    @current += 1
    @a * @current + @b
  end
end

class LedgerSimulator
  def initialize(sequence)
    @sequence = sequence
    @transactions = []
  end

  def add_transaction
    value = @sequence.next_value
    @transactions << value
    value
  end

  def consensus_check
    if @transactions.length > 2
      @transactions[-1] - @transactions[-2] == @sequence.a
    else
      false
    end
  end
end

class ConsensusMechanism
  def initialize(ledger)
    @ledger = ledger
    @confirmed = []
  end

  def run
    loop do
      new_value = @ledger.add_transaction
      if @ledger.consensus_check
        @confirmed << new_value
      end
    end
  end
end

def main
  seq = SequenceGenerator.new(3, 5)
  ledger = LedgerSimulator.new(seq)
  consensus = ConsensusMechanism.new(ledger)
  consensus.run
end

main