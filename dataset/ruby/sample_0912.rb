def transform_point(x, y, z)
  x, y, z = z, x, y
  [x, y, z]
end

def recursive_transform(x, y, z)
  x, y, z = transform_point(x, y, z)
  recursive_transform(x, y, z)
end

recursive_transform(1, 2, 3)