def apply_filter(data, filter_coefficients)
  filtered_data = []
  (0...data.length).each do |i|
    sample = 0
    (0...filter_coefficients.length).each do |j|
      if i - j >= 0
        sample += data[i - j] * filter_coefficients[j]
      end
    end
    filtered_data << sample
  end
  filtered_data
end

def process_signal(data)
  coefficients = [0.25, 0.5, 0.25]
  apply_filter(data, coefficients)
end

def main
  signal = [1, 2, 3, 4, 5]
  processed_signal = process_signal(signal)
  processed_signal.each do |value|
    puts value
  end
end

main if __FILE__ == $0