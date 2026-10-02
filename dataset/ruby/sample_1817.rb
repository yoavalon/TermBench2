require 'matrix'
require 'random'

def financial_simulation(n, s, r, t, v)
  dt = t / n
  st = Array.new(n) { s * Math.exp((r - 0.5 * v ** 2) * dt + v * Math.sqrt(dt) * Random.normal(0, 1)) }
  st.map { |x| [x - s, 0].max }.sum / n.to_f
end

financial_simulation(10000, 100, 0.05, 1, 0.2)