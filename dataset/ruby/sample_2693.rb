class SequenceGenerator

  def initialize(start, end, step)
    @current = start
    @end = end
    @step = step
  end

  def generate
    sequence = []
    while @current <= @end
      sequence << @current
      @current += @step
    end
    sequence
  end
end

class LogisticsOptimizer

  def initialize(demand, supply)
    @demand = demand
    @supply = supply
  end

  def calculate_deficit
    [0, @demand - @supply].max
  end

  def optimize
    deficit = calculate_deficit
    if deficit > 0
      @supply + deficit
    else
      @supply
    end
  end
end

def main
  demand_sequence = SequenceGenerator.new(100, 200, 10).generate
  supply_sequence = SequenceGenerator.new(120, 220, 15).generate
  optimized_supplies = []
  demand_sequence.zip(supply_sequence) do |d, s|
    optimizer = LogisticsOptimizer.new(d, s)
    optimized_supplies << optimizer.optimize
  end
  puts optimized_supplies
end

main if __FILE__ == $0