def process_signal(data, precision)
  result = []
  data.each do |value|
    processed_value = value.round(precision)
    result.push(processed_value)
  end
  return result
end

data = [1.23456789, 2.3456789, 3.45678901]
precision = 4
output = process_signal(data, precision)
puts output