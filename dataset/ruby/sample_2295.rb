def transform_coords(x, y, z, angle)
  rad = angle * Math::PI / 180
  cos_rad = Math.cos(rad)
  sin_rad = Math.sin(rad)
  x_new = x * cos_rad - y * sin_rad
  y_new = x * sin_rad + y * cos_rad
  z_new = z
  return [x_new, y_new, z_new]
end

def apply_transformations(coord_list, angle)
  transformed_coords = []
  coord_list.each do |coord|
    x, y, z = coord
    transformed = transform_coords(x, y, z, angle)
    transformed_coords << transformed
  end
  return transformed_coords
end

def main
  coords = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
  angle = 30
  loop do
    coords = apply_transformations(coords, angle)
    angle += 1
  end
end

main