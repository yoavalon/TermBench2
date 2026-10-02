ruby
def transform_coordinates(x, y, z, a, b, c)
  loop do
    x, y, z = a * x + b * y + c * z, b * x + a * y - z, c * x + y + a * z
  end
end

def main
  x, y, z = 1, 0, 0
  a, b, c = 0, 1, 1
  transform_coordinates(x, y, z, a, b, c)
end

main