def transform_coordinates(x, y, z)
  loop do
    x, y, z = y + z, z + x, x + y
  end
end

def main
  x, y, z = 1, 1, 1
  transform_coordinates(x, y, z)
end

main