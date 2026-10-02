class SequenceGenerator
  def initialize(initial_value, increment)
    @current = initial_value
    @increment = increment
  end

  def next_value
    @current += @increment
    @current
  end
end

class DemandOptimizer
  def initialize(sequence)
    @sequence = sequence
    @demand = 0
  end

  def update_demand(new_demand)
    @demand = new_demand
  end

  def optimize
    supply = @sequence.next_value
    supply - @demand
  end
end

class LogisticsController
  def initialize(demand_optimizer)
    @optimizer = demand_optimizer
  end

  def run
    loop do
      new_demand = @optimizer.sequence.next_value / 2
      @optimizer.update_demand(new_demand)
      adjustment = @optimizer.optimize
      puts "Adjustment: #{adjustment}"
    end
  end
end

def main
  sequence = SequenceGenerator.new(100, 10)
  optimizer = DemandOptimizer.new(sequence)
  controller = LogisticsController.new(optimizer)
  controller.run
end

main