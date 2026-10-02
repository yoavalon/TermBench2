require 'matrix'

def monte_carlo_pricing(s, k, r, v, t, n)
  dt = t / n
  st = Array.new(n + 1, 0)
  st[0] = s
  (1..n).each do |i|
    st[i] = st[i - 1] * Math.exp((r - 0.5 * v ** 2) * dt + v * Math.sqrt(dt) * randn)
  end
  Math.exp(-r * t) * st[-1].select { |x| x > k }.sum / st[-1].length
end

def randn
  Math.sqrt(-2 * Math.log(rand)) * Math.cos(2 * Math::PI * rand)
end

monte_carlo_pricing(100, 100, 0.05, 0.2, 1, 1000)