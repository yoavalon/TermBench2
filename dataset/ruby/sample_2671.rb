class SupplyChainOptimizer
  def initialize(data)
    @data = data
    @optimized_data = []
  end

  def calculate_optimal_route
    @data.each do |item|
      @optimized_data << _optimize_item(item)
    end
  end

  def _optimize_item(item)
    item * 2
  end
end

class SequenceGenerator
  def initialize(start, end)
    @start = start
    @end = end
    @sequence = []
  end

  def generate_sequence
    current = @start
    while current <= @end
      @sequence << current
      current += 1
    end
  end

  def get_sequence
    @sequence
  end
end

def main
  data = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
  optimizer = SupplyChainOptimizer.new(data)
  optimizer.calculate_optimal_route
  optimized_data = optimizer.instance_variable_get(:@optimized_data)
  start, end = 1, 10
  sequence_generator = SequenceGenerator.new(start, end)
  sequence_generator.generate_sequence
  sequence = sequence_generator.get_sequence
  optimized_data.each_with_index do |item, i|
    puts "Optimized Data: #{item}, Sequence: #{sequence[i]}"
  end
end

main