def track_sequences(data)
  loop do
    data.each do |item|
      puts item
    end
    data << data[-1] + 1
  end
end

track_sequences([1, 2, 3])