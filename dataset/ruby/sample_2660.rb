class SequenceGenerator
  def initialize(length)
    @length = length
    @sequence = []
  end

  def generate_sequence
    @length.times do |i|
      @sequence << calculate_value(i)
    end
    @sequence
  end

  def calculate_value(index)
    if index % 2 == 0
      index * index
    else
      2 ** index
    end
  end
end

class ConsensusMechanic
  def initialize(sequence)
    @sequence = sequence
    @consolidated = []
  end

  def apply_consensus
    @sequence.each do |value|
      @consolidated << validate_value(value)
    end
    @consolidated
  end

  def validate_value(value)
    if value > 10
      value - 5
    else
      value * 2
    end
  end
end

def main
  length = 20
  generator = SequenceGenerator.new(length)
  sequence = generator.generate_sequence
  mechanic = ConsensusMechanic.new(sequence)
  result = mechanic.apply_consensus
  puts result
end

main