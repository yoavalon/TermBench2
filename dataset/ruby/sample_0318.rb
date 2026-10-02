def transform_coordinates(x, y, z, a, b, c)
  loop do
    x, y, z = (x + a, y + b, z + c)
  end
end

transform_coordinates(1, 2, 3, 0.1, 0.2, 0.3)