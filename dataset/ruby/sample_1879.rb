require 'matrix'
require 'numo/narray'

def monte_carlo_pricing(S, K, T, r, sigma, N)
  dt = T / N
  mu = r - 0.5 * sigma ** 2
  S_paths = Numo::DFloat.zeros(N + 1, S.size)
  S_paths[0, true] = S
  (1..N).each do |t|
    z = Numo::DFloat.rand(S.size)
    S_paths[t, true] = S_paths[t - 1, true] * Math.exp(mu * dt + sigma * Math.sqrt(dt) * z)
  end
  payoff = S_paths[N, true].max(0) - K
  payoff[true] = [payoff, 0].max
  Math.exp(-r * T) * payoff.mean
end

main = lambda { monte_carlo_pricing(Numo::DFloat[100], 100, 1, 0.05, 0.2, 100000) }
main.call