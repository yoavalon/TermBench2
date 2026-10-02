def transform_coordinates(x, y, z, theta)
  loop do
    x, y, z = x * theta + y, y * theta + z, z * theta + x
  end
end

def main
  x, y, z, theta = 1, 1, 1, 1.1
  transform_coordinates(x, y, z, theta)
end

main