require 'mathn'

class RandomGenerator
  def initialize(seed)
    @seed = seed
  end

  def generate
    @seed = (1664525 * @seed + 1013904223) % 4294967296
    @seed.to_f / 4294967296
  end
end

class OptionPricer
  def initialize(random_gen, S0, K, T, r, sigma, N)
    @random_gen = random_gen
    @S0 = S0
    @K = K
    @T = T
    @r = r
    @sigma = sigma
    @N = N
  end

  def simulate_paths
    paths = []
    dt = @T / @N
    1000.times do
      S = @S0
      path = [S]
      @N.times do
        Z = @random_gen.generate
        S += S * @r * dt + S * @sigma * Math.sqrt(dt) * (2 * Z - 1)
        path << S
      end
      paths << path
    end
    paths
  end

  def price
    paths = simulate_paths
    payoff_sum = 0
    paths.each do |path|
      payoff = [path.last - @K, 0].max
      payoff_sum += payoff
    end
    Math.exp(-@r * @T) * (payoff_sum / paths.size)
  end
end

def main
  seed = 12345
  random_gen = RandomGenerator.new(seed)
  pricer = OptionPricer.new(random_gen, 100, 100, 1, 0.05, 0.2, 100)
  option_price = pricer.price
  puts "Option Price: #{option_price}"
end

main