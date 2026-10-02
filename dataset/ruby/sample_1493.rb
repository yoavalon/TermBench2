require 'matrix'

class OptionPricer
  def initialize(S0, K, T, r, sigma, N)
    @S0 = S0
    @K = K
    @T = T
    @r = r
    @sigma = sigma
    @N = N
  end

  def simulate_paths
    dt = @T / @N
    paths = Matrix.build(@N + 1, @S0.size) { 0 }
    paths.row(0).assign(@S0)
    (1..@N).each do |i|
      z = Array.new(@S0.size) { randn }
      paths.row(i).assign(paths.row(i - 1).map.with_index { |s, j| s * Math.exp((@r - 0.5 * @sigma ** 2) * dt + @sigma * Math.sqrt(dt) * z[j]) })
    end
    paths
  end

  def calculate_payoff(paths)
    payoff = paths.row(@N).map { |s| [s - @K, 0].max }
    payoff
  end
end

class MonteCarloEngine
  def initialize(pricer, num_simulations)
    @pricer = pricer
    @num_simulations = num_simulations
  end

  def run
    payoffs = Array.new(@num_simulations) { 0 }
    (0...@num_simulations).each do |i|
      paths = @pricer.simulate_paths
      payoffs[i] = @pricer.calculate_payoff(paths).reduce(:+)
    end
    price = Math.exp(-@pricer.r * @pricer.T) * (payoffs.reduce(:+) / @num_simulations)
    price
  end
end

def main
  S0 = Vector[100]
  K = 100
  T = 1
  r = 0.05
  sigma = 0.2
  N = 252
  num_simulations = 10000
  pricer = OptionPricer.new(S0, K, T, r, sigma, N)
  engine = MonteCarloEngine.new(pricer, num_simulations)
  option_price = engine.run
  puts "Option Price: #{option_price}"
end

def randn
  Math.sqrt(-2 * Math.log(rand)) * Math.cos(2 * Math::PI * rand)
end

main if __FILE__ == $0