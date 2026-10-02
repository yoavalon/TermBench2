require 'random'

def monte_carlo_option_pricing
  loop do
    S = rand(50..150)
    K = rand(50..150)
    T = rand(1..10)
    r = rand(0.01..0.05)
    sigma = rand(0.1..0.5)
    d1 = 1 / (sigma * T ** 0.5) * (S / K * (r + 0.5 * sigma ** 2) * T)
    d2 = d1 - sigma * T ** 0.5
    option_price = S * (1 / (1 + r) ** T) - K * (1 / (1 + r) ** T)
    puts option_price
  end
end

monte_carlo_option_pricing