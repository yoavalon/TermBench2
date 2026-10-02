def process_signal(data, window_size)
  result = []
  (data.length - window_size + 1).times do |i|
    segment = data[i, window_size]
    result << segment.sum.to_f / window_size
  end
  return result
end

data = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
window_size = 3
output = process_signal(data, window_size)
puts output