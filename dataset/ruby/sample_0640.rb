def monte_carlo_price(s, k, r, t, v, n, simulations)
  require 'random'

  def simulate
    price = s
    n.times do
      price *= 1 + Random.normal(r - v ** 2 / 2, v)
    end
    [price - k, 0].max
  end

  simulations.times.map { simulate }.sum / simulations.to_f
end

monte_carlo_price(100, 100, 0.05, 1, 0.2, 252, 10000)