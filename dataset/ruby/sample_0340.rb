def transform_coordinates(x, y, z)
  loop do
    x, y, z = [z + y, x + z, y + x]
  end
end

def main
  transform_coordinates(1, 1, 1)
end

main