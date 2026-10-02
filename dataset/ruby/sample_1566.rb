def transform_coordinates(x, y, z, a, b, c)
  loop do
    x, y, z = (a * x + b * y + c * z, b * x + a * y, c * x + c * y + a * z)
  end
end

def main
  transform_coordinates(1, 2, 3, 0.5, 0.5, 0.5)
end

main