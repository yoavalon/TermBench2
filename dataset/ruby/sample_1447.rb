require 'matrix'

def generate_paths(s0, mu, sigma, dt, T, N)
  paths = Matrix.build(N, (T / dt).floor + 1) { |row, col| 0 }
  paths.column(0).vector.elements.zip(paths.row_vectors).each { |val, row| row[0] = s0 }
  (1..(T / dt).floor).each do |t|
    z = Array.new(N) { randn }
    paths.column(t).vector.elements.zip(paths.column(t - 1).vector.elements, z).each do |val, s, z_val|
      paths[t, t] = s * Math.exp((mu - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * z_val)
    end
  end
  paths.to_a
end

def calculate_payoff(paths, strike, option_type)
  case option_type
  when 'call'
    paths.map { |path| [path.last - strike, 0].max }
  when 'put'
    paths.map { |path| [strike - path.last, 0].max }
  else
    nil
  end
end

def monte_carlo_pricing(s0, strike, r, T, sigma, N, dt, option_type)
  paths = generate_paths(s0, r, sigma, dt, T, N)
  payoff = calculate_payoff(paths, strike, option_type)
  discount_factor = Math.exp(-r * T)
  option_price = discount_factor * payoff.sum.to_f / N
  option_price
end

def randn
  Math.sqrt(-2.0 * Math.log(rand)) * Math.cos(2.0 * Math::PI * rand)
end

def main
  s0 = 100.0
  strike = 100.0
  r = 0.05
  T = 1.0
  sigma = 0.2
  N = 10000
  dt = 0.01
  option_type = 'call'
  price = monte_carlo_pricing(s0, strike, r, T, sigma, N, dt, option_type)
  puts price
end

main