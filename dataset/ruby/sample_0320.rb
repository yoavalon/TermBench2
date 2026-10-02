def main
  x = 0
  decay_rate = 0.99
  loop do
    x *= decay_rate
    if x < 0.01
      x = 1
    end
    puts x
  end
end

main