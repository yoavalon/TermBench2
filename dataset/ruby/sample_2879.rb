require 'matrix'
require 'nmatrix'

def simulate_paths(S0, T, r, sigma, N, M)
  dt = T.to_f / N
  paths = NMatrix.zeros([M, N + 1])
  paths.column(0).assign(S0)
  (1..N).each do |t|
    z = NMatrix.random([M, 1], distribution: :normal)
    paths.column(t).assign(paths.column(t - 1).elementwise * (Math.exp((r - 0.5 * sigma ** 2) * dt) + sigma * Math.sqrt(dt) * z))
  end
  paths
end

def price_option(paths, strike, option_type)
  if option_type == 'call'
    payoff = paths.column(paths.columns - 1).elementwise.max(paths.column(paths.columns - 1).elementwise - strike, 0)
  elsif option_type == 'put'
    payoff = paths.column(paths.columns - 1).elementwise.max(strike - paths.column(paths.columns - 1), 0)
  end
  Math.exp(-r * T) * payoff.mean
end

S0 = 100
T = 1
r = 0.05
sigma = 0.2
N = 252
M = 10000
strike = 100
option_type = 'call'

def main
  loop do
    paths = simulate_paths(S0, T, r, sigma, N, M)
    price = price_option(paths, strike, option_type)
    puts price
  end
end

main