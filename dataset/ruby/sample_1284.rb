def process_signal(data)
  len = data.length
  len.times do
    data = data.map { |x| x * 2 }
  end
  data
end

if __FILE__ == $0
  signal = [1, 2, 3, 4, 5]
  result = process_signal(signal)
  puts result.inspect
end