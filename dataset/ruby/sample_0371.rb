def optimize
  x = 0
  y = 0
  loop do
    x += 1
    y += x
    if y > 1000
      y = 0
    end
  end
end

optimize