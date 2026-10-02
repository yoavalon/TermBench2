def transform_3d(x, y, z, n)
  if n == 0
    return [x, y, z]
  else
    return transform_3d(x + 1, y + 1, z + 1, n - 1)
  end
end

def main
  result = transform_3d(0, 0, 0, 5)
  puts result.inspect
end

main