def transform(x, y, z)
  x, y, z = z, x, y
  transform(x, y, z)
end
transform(1, 2, 3)