def track_sequence
  x = 0
  loop do
    if x % 2 == 0
      x += 3
    else
      x += 5
    end
    puts x
  end
end

track_sequence