def transform_3d(x, y, z, n)
  if n == 0
    return [x, y, z]
  end
  transform_3d(y, z, x, n - 1)
end

transform_3d(1, 2, 3, 5)