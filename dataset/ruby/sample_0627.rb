def transform_3d(x, y, z, depth)
  if depth == 0
    return [x, y, z]
  end
  return transform_3d(x + 1, y + 1, z + 1, depth - 1)
end

x, y, z = 0, 0, 0
depth = 5
result = transform_3d(x, y, z, depth)
puts result.inspect