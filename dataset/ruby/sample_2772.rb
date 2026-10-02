def digital_signal_processor
  x = 0
  loop do
    y = x ** 2 + 2 * x + 1
    z = y * 0.5
    puts z
    x += 1
  end
end

digital_signal_processor