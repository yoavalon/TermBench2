require 'mathn'

class OptionPricing
  def initialize(S, K, T, r, sigma)
    @S = S
    @K = K
    @T = T
    @r = r
    @sigma = sigma
  end

  def calculate_price(n_simulations, depth)
    if depth == 0
      black_scholes(@S, @K, @T, @r, @sigma)
    else
      monte_carlo(n_simulations, depth)
    end
  end

  def black_scholes(S, K, T, r, sigma)
    d1 = (Math.log(S / K) + (r + 0.5 * sigma ** 2) * T) / (sigma * Math.sqrt(T))
    d2 = d1 - sigma * Math.sqrt(T)
    S * Math.exp(-r * T) * norm_cdf(d1) - K * Math.exp(-r * T) * norm_cdf(d2)
  end

  def norm_cdf(x)
    (1.0 + Math.erf(x / Math.sqrt(2.0))) / 2.0
  end

  def monte_carlo(n_simulations, depth)
    payoff_sum = 0
    n_simulations.times do
      price_path = price_path_simulation
      payoff_sum += [price_path[-1] - @K, 0].max
    end
    payoff_sum / n_simulations * Math.exp(-@r * @T)
  end

  def price_path_simulation
    path = [@S]
    (@T.to_i).times do
      drift = @r * path[-1] * (1.0 / 252)
      diffusion = path[-1] * @sigma * Math.sqrt(1.0 / 252) * rand.gaussian
      path << path[-1] + drift + diffusion
    end
    path
  end
end

def main
  S = 100
  K = 100
  T = 1
  r = 0.05
  sigma = 0.2
  n_simulations = 1000
  depth = 2
  pricing_model = OptionPricing.new(S, K, T, r, sigma)
  option_price = pricing_model.calculate_price(n_simulations, depth)
  puts "Option Price: #{option_price}"
end

main