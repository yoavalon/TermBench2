def transform_coordinates(x, y, z, a, b, c)
  loop do
    x, y, z = (a * x + b * y + c * z), (b * x + a * y - c * z), (c * x - b * y + a * z)
  end
end

def main
  transform_coordinates(1, 0, 0, 2, 0, 0)
end

main