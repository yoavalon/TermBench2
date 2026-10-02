require 'random'

class OptionPricing

  def initialize(S0, K, T, r, sigma, N)
    @S0 = S0
    @K = K
    @T = T
    @r = r
    @sigma = sigma
    @N = N
  end

  def _simulate_paths(S0, T, r, sigma, N)
    dt = T / N
    paths = [S0]
    (1..N).each do
      z = Random.gaussian(0, 1)
      S = paths[-1] * (1 + r * dt + sigma * z * dt ** 0.5)
      paths << S
    end
    paths
  end

  def _option_value(paths, K)
    value = 0
    paths.each do |S_T|
      value += [S_T - K, 0].max
    end
    value / paths.length
  end

  def price
    paths = _simulate_paths(@S0, @T, @r, @sigma, @N)
    _option_value(paths, @K)
  end
end

def main
  S0 = 100
  K = 100
  T = 1
  r = 0.05
  sigma = 0.2
  N = 1000
  option = OptionPricing.new(S0, K, T, r, sigma, N)
  result = option.price
  puts "Option price: #{result}"
end

main