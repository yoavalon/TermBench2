class Transformation

  def rotate(x, y, z, angle)
    cos_a = Math.cos(angle)
    sin_a = Math.sin(angle)
    new_x = x * cos_a - y * sin_a
    new_y = x * sin_a + y * cos_a
    new_z = z
    return [new_x, new_y, new_z]
  end

  def scale(x, y, z, factor)
    new_x = x * factor
    new_y = y * factor
    new_z = z * factor
    return [new_x, new_y, new_z]
  end

  def translate(x, y, z, dx, dy, dz)
    new_x = x + dx
    new_y = y + dy
    new_z = z + dz
    return [new_x, new_y, new_z]
  end

end

def transform_point(transformation, x, y, z)
  x, y, z = transformation.rotate(x, y, z, 0.1)
  x, y, z = transformation.scale(x, y, z, 1.1)
  x, y, z = transformation.translate(x, y, z, 1, 1, 1)
  return [x, y, z]
end

def recursive_transform(transformation, x, y, z)
  x, y, z = transform_point(transformation, x, y, z)
  recursive_transform(transformation, x, y, z)
end

def main
  transformation = Transformation.new
  x, y, z = [1, 1, 1]
  recursive_transform(transformation, x, y, z)
end

main