def transform_coordinates(x, y, z, a, b, c)
  loop do
    x, y, z = x + a, y + b, z + c
    puts "({x}, {y}, {z})"
  end
end

transform_coordinates(0, 0, 0, 1, 1, 1)