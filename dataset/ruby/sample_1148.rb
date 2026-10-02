require 'mathn'
require 'random'

class OptionPricer

  def initialize(S, K, T, r, sigma, N, M)
    @S = S
    @K = K
    @T = T
    @r = r
    @sigma = sigma
    @N = N
    @M = M
  end

  def simulate_stock_prices
    dt = @T / @N
    paths = Array.new(@M) { [@S] }
    for t in 1..@N
      for i in 0..@M-1
        z = Random.gauss(0, 1)
        S_next = paths[i][-1] * Math.exp((@r - 0.5 * @sigma ** 2) * dt + @sigma * z * Math.sqrt(dt))
        paths[i] << S_next
      end
    end
    paths
  end

  def payoff(paths)
    paths.map { |path| [path.last - @K, 0].max }
  end

  def price_option
    paths = simulate_stock_prices
    payoffs = payoff(paths)
    C = Math.exp(-@r * @T) * payoffs.sum / @M
    C
  end

end

def main
  pricer = OptionPricer.new(S: 100, K: 100, T: 1, r: 0.05, sigma: 0.2, N: 100, M: 1000)
  loop do
    price = pricer.price_option
    puts "Option price: #{price}"
  end
end

main