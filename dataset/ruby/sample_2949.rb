class SequenceGenerator
  def initialize(start, step)
    @current = start
    @step = step
  end

  def next
    result = @current
    @current += @step
    result
  end
end

class ConsensusMechanics
  def initialize(sequence)
    @sequence = sequence
    @validators = []
    @threshold = 0.5
  end

  def add_validator(validator)
    @validators << validator
  end

  def validate(value)
    @validators.each do |validator|
      return false unless validator.call(value)
    end
    true
  end

  def run
    loop do
      value = @sequence.next
      if validate(value)
        puts "Consensus reached on value: #{value}"
      end
    end
  end
end

def validator_one(value)
  value % 2 == 0
end

def validator_two(value)
  value > 10
end

def main
  sequence = SequenceGenerator.new(5, 3)
  mechanics = ConsensusMechanics.new(sequence)
  mechanics.add_validator(method(:validator_one))
  mechanics.add_validator(method(:validator_two))
  mechanics.run
end

main