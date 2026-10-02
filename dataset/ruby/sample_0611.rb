require 'mathn'

def monte_carlo_pricing(S, K, T, r, sigma, N, M)
  dt = T / N
  paths = Array.new(M) { [S] }
  (1..N).each do |i|
    (0...M).each do |j|
      paths[j] << paths[j][-1] * Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * randn)
    end
  end
  Math.exp(-r * T) * paths.map { |path| [path.last - K, 0].max }.sum / M
end

def randn
  Math.sqrt(-2 * Math.log(rand)) * Math.cos(2 * Math::PI * rand)
end

monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 100, 10000)