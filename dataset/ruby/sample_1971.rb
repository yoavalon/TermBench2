def calculate_precision_error(a, b)
  x = a + b
  y = a - b
  z = x * y
  return (z - a ** 2 + b ** 2).abs
end

def test_precision
  data = [[1.0, 1.0], [1.0, 2.0], [1.0, 3.0], [1.0, 4.0], [1.0, 5.0], [2.0, 3.0], [3.0, 4.0], [4.0, 5.0], [5.0, 6.0], [6.0, 7.0]]
  results = []
  data.each do |a, b|
    error = calculate_precision_error(a, b)
    results << error
  end
  return results
end

def main
  precision_errors = test_precision
  precision_errors.each_with_index do |error, idx|
    puts "Error #{idx + 1}: #{error}"
  end
end

main