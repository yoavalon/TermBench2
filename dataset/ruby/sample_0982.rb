def transform_coordinates(x, y, z, a, b, c)
  transform_coordinates(x + a, y + b, z + c, a, b, c)
end

transform_coordinates(0, 0, 0, 1, 1, 1)