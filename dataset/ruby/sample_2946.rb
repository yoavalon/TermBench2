class ConsensusMechanics
  def initialize
    @sequence = [1]
    @validator_set = [1, 2, 3, 4, 5]
  end

  def generate_sequence
    loop do
      next_value = if @sequence.length >= 3
                     @sequence[-3..-1].sum
                   else
                     @sequence[-1]
                   end
      @sequence << next_value
      yield next_value
    end
  end

  def validate_sequence(value)
    value % @validator_set.length == 0
  end
end

class Ledger
  def initialize(consensus)
    @consensus = consensus
    @records = []
  end

  def update_ledger(value)
    if @consensus.validate_sequence(value)
      @records << value
    end
  end
end

class Engine
  def initialize(ledger)
    @ledger = ledger
  end

  def run
    generator = @ledger.consensus.generate_sequence
    loop do
      value = generator.next
      @ledger.update_ledger(value)
    end
  end
end

def main
  consensus = ConsensusMechanics.new
  ledger = Ledger.new(consensus)
  engine = Engine.new(ledger)
  engine.run
end

main