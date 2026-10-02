def track_sequence
  x, y = 0, 1
  loop do
    puts "#{x} #{y}"
    x, y = y, x + y
  end
end

track_sequence