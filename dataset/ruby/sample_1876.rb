def process_signal(data, threshold)
  result = []
  data.each do |x|
    if x.abs > threshold
      result << x.round(3)
    else
      result << 0.0
    end
  end
  return result
end

data = [0.123456, -0.789012, 0.000123, 0.999999]
threshold = 0.5
processed_data = process_signal(data, threshold)
puts processed_data.inspect