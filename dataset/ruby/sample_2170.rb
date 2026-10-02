def simulate
  x, y = 0.1, 0.2
  loop do
    z = x + y
    if z > 1
      x, y = y, z - 1
    else
      x, y = y, z
    end
  end
end

simulate