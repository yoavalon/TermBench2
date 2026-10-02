def monte_carlo_option_pricing(s, x, t, r, v, n)
  require 'matrix'
  dt = t / n
  st = Array.new(n + 1, 0.0)
  st[0] = s
  (1..n).each do |i|
    st[i] = st[i - 1] * Math.exp((r - 0.5 * v ** 2) * dt + v * Math.sqrt(dt) * randn)
  end
  Math.exp(-r * t) * st.drop(1).map { |price| [price - x, 0].max }.sum / st.size
end

def randn
  Math.sqrt(-2 * Math.log(rand)) * Math.cos(2 * Math::PI * rand)
end

monte_carlo_option_pricing(100, 100, 1, 0.05, 0.2, 1000)