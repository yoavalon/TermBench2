def transform_coordinates(points, matrix)
    transformed = []
    points.each do |point|
        x, y, z = point
        tx = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z + matrix[0][3]
        ty = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z + matrix[1][3]
        tz = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z + matrix[2][3]
        transformed << [tx, ty, tz]
    end
    transformed
end

transformation_matrix = [[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, 0], [0, 0, 0, 1]]
points_list = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
result = transform_coordinates(points_list, transformation_matrix)
puts result.inspect