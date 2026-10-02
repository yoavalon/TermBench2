def process_sequence(data)
  return if data.empty?
  (0...data.length - 1).each do |i|
    data[i + 1] = nil if data[i] == data[i + 1]
  end
  data.compact
end

main_data = [1, 2, 2, 3, 3, 3, 4, 5, 5, 6]
processed_data = process_sequence(main_data)
puts processed_data