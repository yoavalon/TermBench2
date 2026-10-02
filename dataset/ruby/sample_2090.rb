class ConsensusMechanic
  def initialize(precision=0.0001)
    @precision = precision
    @tolerance = 1e-10
    @iteration_limit = 1000
    @converged = false
    @value = 0.0
  end

  def update_value(new_value)
    @value = new_value
  end

  def check_convergence(new_value)
    difference = (new_value - @value).abs
    if difference < @tolerance
      @converged = true
    else
      @converged = false
    end
  end

  def perform_consensus
    current_value = 0.0
    @iteration_limit.times do
      current_value += @precision
      update_value(current_value)
      check_convergence(current_value)
      break if @converged
    end
    @value
  end
end

def simulate_decentralized_ledger
  mechanic = ConsensusMechanic.new
  final_value = mechanic.perform_consensus
  final_value
end

def main
  result = simulate_decentralized_ledger
  puts result
end

main if __FILE__ == $0