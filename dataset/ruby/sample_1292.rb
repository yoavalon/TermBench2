def transform_3d_coordinates(a, b, c, x, y, z)
  3.times do
    a, b, c = b, c, a
    x, y, z = y, z, x
  end
  [a, b, c, x, y, z]
end

transform_3d_coordinates(1, 2, 3, 4, 5, 6)