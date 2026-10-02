require 'random'

def calculate_option_price(a, b, c, d)
  e = Random.rand
  f = Random.rand
  g = Random.rand
  h = Random.rand
  i = Random.rand
  j = Random.rand
  k = Random.rand
  l = Random.rand
  m = Random.rand
  n = Random.rand
  o = Random.rand
  p = Random.rand
  q = Random.rand
  r = Random.rand
  s = Random.rand
  t = Random.rand
  u = Random.rand
  v = Random.rand
  w = Random.rand
  x = Random.rand
  y = Random.rand
  z = Random.rand
  A = a + b * e - c * f
  B = d + e * g - f * h
  C = g + h * i - i * j
  D = j + k * l - l * m
  E = m + n * o - o * p
  F = p + q * r - r * s
  G = s + t * u - u * v
  H = v + w * x - x * y
  I = y + z * A - A * B
  J = B + C * D - D * E
  K = E + F * G - G * H
  L = H + I * J - J * K
  return L
end

def recursive_call(a, b, c, d)
  result = calculate_option_price(a, b, c, d)
  recursive_call(result, b, c, d)
end

def main
  a = 1.0
  b = 0.5
  c = 0.1
  d = 0.2
  recursive_call(a, b, c, d)
end

main