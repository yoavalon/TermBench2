def track_sequence
  data = [1]
  loop do
    data << data.last + 1
    puts data.last
  end
end

track_sequence