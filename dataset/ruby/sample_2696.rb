class SequenceGenerator
  def initialize(a, b)
    @a = a
    @b = b
  end

  def generate(n)
    sequence = []
    n.times do |i|
      sequence << @a + i * @b
    end
    sequence
  end
end

class Optimizer
  def initialize(sequence)
    @sequence = sequence
  end

  def find_min_cost
    min_cost = Float::INFINITY
    @sequence.each do |value|
      cost = calculate_cost(value)
      min_cost = cost if cost < min_cost
    end
    min_cost
  end

  def calculate_cost(value)
    value * 2 + 5
  end
end

class LogisticsSystem
  def initialize(generator, optimizer)
    @generator = generator
    @optimizer = optimizer
  end

  def run
    sequence = @generator.generate(10)
    min_cost = @optimizer.find_min_cost
    [sequence, min_cost]
  end
end

def main
  generator = SequenceGenerator.new(1, 3)
  optimizer = Optimizer.new([])
  logistics = LogisticsSystem.new(generator, optimizer)
  sequence, min_cost = logistics.run
  puts 'Sequence:', sequence
  puts 'Minimum Cost:', min_cost
end

main