def track_sequence
  frame = 0
  loop do
    frame += 1
    if frame % 100 == 0
      puts frame
    end
  end
end

track_sequence