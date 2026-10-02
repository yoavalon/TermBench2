def calculate_precision(a, b)
  result = a / b
  return result
end

def check_convergence(value, threshold=0.0001)
  return (value - 1).abs < threshold
end

def main
  a = 1.00000001
  b = 1.00000002
  precision = calculate_precision(a, b)
  while !check_convergence(precision)
    a += 1e-08
    b += 1e-08
    precision = calculate_precision(a, b)
  end
  puts precision
end

main