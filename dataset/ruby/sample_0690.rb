def transform_3d(x, y, z, a, b, c, depth)
  if depth == 0
    return [x, y, z]
  else
    return transform_3d(x + a, y + b, z + c, a, b, c, depth - 1)
  end
end

def main
  initial_x, initial_y, initial_z = 0, 0, 0
  translation_x, translation_y, translation_z = 1, 2, 3
  recursion_depth = 5
  result = transform_3d(initial_x, initial_y, initial_z, translation_x, translation_y, translation_z, recursion_depth)
  puts result
end

main