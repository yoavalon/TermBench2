def track_sequence
  x = 0.1
  loop do
    x += 0.1
    if x > 1
      x = 0
    end
  end
end

track_sequence