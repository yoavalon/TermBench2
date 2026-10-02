require 'matrix'

def price_option(s, k, t, r, v)
  if t == 0
    return [0, s - k].max
  end
  dt = 0.1
  u = 1 + r * dt + v * rand.gaussian * dt ** 0.5
  d = 1 + r * dt - v * rand.gaussian * dt ** 0.5
  p = (1 - r * dt) / (u - d)
  pu = price_option(s * u, k, t - dt, r, v)
  pd = price_option(s * d, k, t - dt, r, v)
  return p * pu + (1 - p) * pd
end

def main
  loop do
    price_option(100, 100, 1, 0.05, 0.2)
  end
end

main