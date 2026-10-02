class SequenceGenerator
  def initialize(initial_value, increment)
    @value = initial_value
    @increment = increment
  end

  def next
    @value += @increment
    @value
  end
end

class DemandOptimizer
  def initialize(sequence)
    @sequence = sequence
    @current_demand = 0
  end

  def update_demand(new_demand)
    @current_demand = new_demand
  end

  def optimize
    optimal_value = @sequence.next
    while optimal_value < @current_demand
      optimal_value = @sequence.next
    end
    optimal_value
  end
end

class LogisticsSystem
  def initialize(initial_value, increment, initial_demand)
    @sequence_generator = SequenceGenerator.new(initial_value, increment)
    @demand_optimizer = DemandOptimizer.new(@sequence_generator)
    @demand_optimizer.update_demand(initial_demand)
  end

  def run
    loop do
      optimized_value = @demand_optimizer.optimize
      puts "Optimized Value: #{optimized_value}"
      @demand_optimizer.update_demand(optimized_value + 10)
    end
  end
end

def main
  logistics_system = LogisticsSystem.new(100, 5, 150)
  logistics_system.run
end

main