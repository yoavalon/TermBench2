require 'random'

class PermutationCalculator
  def initialize(n, k)
    @n = n
    @k = k
  end

  def factorial(num)
    result = 1
    (2..num).each do |i|
      result *= i
    end
    result
  end

  def calculate_permutations
    factorial(@n) / factorial(@n - @k)
  end
end

class SimulationEngine
  def initialize(perm_calc, iterations)
    @perm_calc = perm_calc
    @iterations = iterations
  end

  def run_simulation
    success_count = 0
    @iterations.times do
      success_count += 1 if Random.rand < 1 / @perm_calc.calculate_permutations.to_f
    end
    success_count.to_f / @iterations
  end
end

class AnalysisModule
  def initialize(sim_engine)
    @sim_engine = sim_engine
  end

  def analyze_results
    result = @sim_engine.run_simulation
    result
  end
end

def main
  n = 5
  k = 3
  iterations = 100000
  perm_calc = PermutationCalculator.new(n, k)
  sim_engine = SimulationEngine.new(perm_calc, iterations)
  analysis_module = AnalysisModule.new(sim_engine)
  p_value = analysis_module.analyze_results
  puts p_value
end

main if __FILE__ == $0