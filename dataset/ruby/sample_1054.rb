def simulate_price(path, steps, strike, rate, vol, spot)
  if steps > 0
    drift = (rate - 0.5 * vol * vol) * steps
    diff = vol * (path[steps - 1] - spot)
    path << spot + drift + diff
    return simulate_price(path, steps - 1, strike, rate, vol, spot)
  end
  return path
end

def price_option(paths, strike, rate, steps)
  def payoff(path)
    final_price = path.last
    return [final_price - strike, 0].max * 2.71828 ** (-rate * steps)
  end
  return paths.map { |path| payoff(path) }.sum / paths.size
end

def main
  strike = 100
  rate = 0.05
  vol = 0.2
  spot = 100
  steps = 100

  def generate_paths(path, depth)
    if depth > 0
      path1 = path + [path.last * 1.01]
      path2 = path + [path.last * 0.99]
      return generate_paths(path1, depth - 1) + generate_paths(path2, depth - 1)
    end
    return [path]
  end
  paths = generate_paths([spot], steps)
  option_price = price_option(paths, strike, rate, steps)
  puts option_price
  main
end

main