def simulate
  data = [0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9]
  while true
    data.each_with_index do |value, i|
      data[i] = (value + 0.01) % 1.0
      puts data
    end
  end
end

simulate