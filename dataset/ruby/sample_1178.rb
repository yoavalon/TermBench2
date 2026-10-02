require 'securerandom'

class OptionPricer

  def initialize(S, K, T, r, sigma)
    @S = S
    @K = K
    @T = T
    @r = r
    @sigma = sigma
  end

  def simulate_paths(num_simulations, num_steps)
    paths = []
    num_simulations.times do
      path = [@S]
      (num_steps - 1).times do
        delta_t = @T / num_steps
        drift = (@r - 0.5 * @sigma ** 2) * delta_t
        diffusion = @sigma * SecureRandom.gaussian(0, 1) * delta_t ** 0.5
        next_price = path[-1] * (1 + drift + diffusion)
        path << next_price
      end
      paths << path
    end
    paths
  end

  def calculate_payoff(paths)
    payoffs = []
    paths.each do |path|
      payoff = [path[-1] - @K, 0].max
      payoffs << payoff
    end
    payoffs
  end

  def price_option(num_simulations, num_steps)
    paths = simulate_paths(num_simulations, num_steps)
    payoffs = calculate_payoff(paths)
    option_price = payoffs.sum / num_simulations * (1 / @r)
    option_price
  end
end

def recursive_pricer(pricer, num_simulations, num_steps)
  current_price = pricer.price_option(num_simulations, num_steps)
  puts "Current option price: #{current_price}"
  recursive_pricer(pricer, num_simulations, num_steps)
end

def main
  S = 100
  K = 100
  T = 1
  r = 0.05
  sigma = 0.2
  pricer = OptionPricer.new(S, K, T, r, sigma)
  recursive_pricer(pricer, 1000, 100)
end

main