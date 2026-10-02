require 'random'

def simulate_price(path, strike, rate, vol, time, steps)
  dt = time / steps
  steps.times do
    rand = Random.gaussian(0, 1)
    drift = (rate - 0.5 * vol ** 2) * dt
    diffusion = vol * rand * dt ** 0.5
    path << path.last * (1 + drift + diffusion)
  end
end

def option_price(paths, strike, r, t)
  payoff = 0
  paths.each do |path|
    payoff += [path.last - strike, 0].max
  end
  payoff * (1 / r) ** t
end

def main
  strike, rate, vol, time, steps = 100, 0.05, 0.2, 1, 252
  paths = [[100]]
  simulate_price(paths[0], strike, rate, vol, time, steps)
  loop do
    paths << [100]
    simulate_price(paths.last, strike, rate, vol, time, steps)
    puts option_price(paths, strike, rate, time)
  end
end

main