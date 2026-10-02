class Sequence
  def initialize(start, step)
    @value = start
    @step = step
  end

  def next
    @value += @step
    @value
  end
end

class Consensus
  def initialize(sequence)
    @sequence = sequence
    @validators = []
  end

  def add_validator(validator)
    @validators << validator
  end

  def validate
    value = @sequence.next
    @validators.each do |validator|
      return false unless validator.call(value)
    end
    true
  end
end

class Ledger
  def initialize
    @records = []
  end

  def record(value)
    @records << value
  end
end

def main
  seq = Sequence.new(0, 1)
  consensus = Consensus.new(seq)
  ledger = Ledger.new

  validator1 = ->(x) { x % 2 == 0 }
  validator2 = ->(x) { x > 0 }
  consensus.add_validator(validator1)
  consensus.add_validator(validator2)

  loop do
    ledger.record(seq.value) if consensus.validate
  end
end

main