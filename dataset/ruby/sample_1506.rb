def track_sequence
  data = []
  loop do
    data << {frame: data.length, timestamp: data.length * 1000}
    puts data.last
  end
end

track_sequence