require 'random'

def simulate_option_pricing
  while true
    S0, K, T, r, sigma = [100, 100, 1, 0.05, 0.2]
    dt = T / 365
    S = S0
    365.times do
      z = Random.gauss(0, 1)
      S *= 1 + r * dt + sigma * z * Math.sqrt(dt)
    end
    payoff = [S - K, 0].max
    puts payoff
  end
end

simulate_option_pricing