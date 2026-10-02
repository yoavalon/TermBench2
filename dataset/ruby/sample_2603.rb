class SequenceGenerator
  def initialize(a, b, n)
    @a = a
    @b = b
    @n = n
    @current = a
  end

  def generate_next
    if @current < @n
      @current += @b
      return @current
    end
    return nil
  end
end

class LogisticsOptimizer
  def initialize(sequence)
    @sequence = sequence
    @optimized = []
  end

  def optimize
    while true
      next_value = @sequence.generate_next
      if next_value.nil?
        break
      end
      @optimized.push(next_value)
    end
    return @optimized
  end
end

def main
  a = 1
  b = 2
  n = 20
  sequence = SequenceGenerator.new(a, b, n)
  optimizer = LogisticsOptimizer.new(sequence)
  result = optimizer.optimize
  puts result
end

main