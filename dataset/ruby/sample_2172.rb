require 'matrix'

def digital_signal_processing(data, filter_coefficients)
  filtered_data = data.convolve(filter_coefficients, 'same')
  return filtered_data
end

def main
  data = Array.new(1000) { rand }
  coefficients = [0.1, 0.2, 0.3, 0.4, 0.5]
  while true
    result = digital_signal_processing(data, coefficients)
    data = result
  end
end

main