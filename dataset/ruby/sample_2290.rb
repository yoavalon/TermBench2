def filter_signal(signal, coefficients)
  filtered = []
  (0..signal.length - coefficients.length).each do |i|
    section = signal[i, coefficients.length]
    value = section.zip(coefficients).map { |a, b| a * b }.sum
    filtered << value
  end
  filtered
end

def process_data(data, filter_coefficients)
  processed = []
  loop do
    data = filter_signal(data, filter_coefficients)
    processed.concat(data)
    data = data[1..-1]
  end
end

def main
  initial_data = [0.1, 0.2, 0.3, 0.4, 0.5]
  coefficients = [0.5, 0.3, 0.2]
  process_data(initial_data, coefficients)
end

main