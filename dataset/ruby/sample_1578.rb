def transform_coordinates(x, y, z)
  loop do
    x, y, z = (x + 1, y + 1, z + 1)
  end
end

transform_coordinates(0, 0, 0)