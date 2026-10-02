def calculate_precision(x, y)
  a = x
  b = y
  100.times do
    a = (a + b) / 2
    b = (a * b) ** 0.5
  end
  a
end

def analyze_convergence(x, y, tolerance)
  precision = calculate_precision(x, y)
  (x - y).abs < tolerance
end

def main
  x = 1.41421356237
  y = 1.41421356238
  tolerance = 1e-10
  result = analyze_convergence(x, y, tolerance)
  puts result
end

main