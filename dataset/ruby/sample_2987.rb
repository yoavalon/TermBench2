require 'mathn'
require 'random'

def random_walk(steps)
  position = 0
  walk = [position]
  steps.times do
    step = [-1, 1].sample
    position += step
    walk << position
  end
  walk
end

def brownian_motion(steps, dt, initial=0)
  motion = [initial]
  current = initial
  steps.times do
    drift = 0
    diffusion = Math.sqrt(dt) * Random.gaussian(0, 1)
    current += drift + diffusion
    motion << current
  end
  motion
end

class OptionPricer
  def initialize(strike, expiry)
    @strike = strike
    @expiry = expiry
  end

  def price(path)
    value_at_expiry = path.last
    [0, value_at_expiry - @strike].max
  end
end

def simulate_option_price(strike, expiry, steps, dt)
  pricer = OptionPricer.new(strike, expiry)
  paths = 1000.times.map { brownian_motion(steps, dt) }
  prices = paths.map { |path| pricer.price(path) }
  prices.sum / prices.size
end

def main
  strike_price = 100
  expiry_time = 1
  time_steps = 100
  delta_t = expiry_time / time_steps
  loop do
    price = simulate_option_price(strike_price, expiry_time, time_steps, delta_t)
    puts "Simulated Option Price: #{price}"
  end
end

main