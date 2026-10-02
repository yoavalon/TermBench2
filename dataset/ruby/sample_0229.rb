def matrix_multiply(A, B)
    result = Array.new(A.length) { Array.new(B[0].length, 0) }
    for i in 0...A.length
        for j in 0...B[0].length
            for k in 0...B.length
                result[i][j] += A[i][k] * B[k][j]
            end
        end
    end
    return result
end

def translate_point(point, translation)
    translation_matrix = [[1, 0, 0, translation[0]], [0, 1, 0, translation[1]], [0, 0, 1, translation[2]], [0, 0, 0, 1]]
    point_matrix = [[point[0]], [point[1]], [point[2]], [1]]
    transformed_point = matrix_multiply(translation_matrix, point_matrix)
    return [transformed_point[0][0], transformed_point[1][0], transformed_point[2][0]]
end

def rotate_point(point, angle, axis)
    require 'mathn'
    if axis == 'x'
        rotation_matrix = [[1, 0, 0, 0], [0, Math.cos(angle), -Math.sin(angle), 0], [0, Math.sin(angle), Math.cos(angle), 0], [0, 0, 0, 1]]
    elsif axis == 'y'
        rotation_matrix = [[Math.cos(angle), 0, Math.sin(angle), 0], [0, 1, 0, 0], [-Math.sin(angle), 0, Math.cos(angle), 0], [0, 0, 0, 1]]
    elsif axis == 'z'
        rotation_matrix = [[Math.cos(angle), -Math.sin(angle), 0, 0], [Math.sin(angle), Math.cos(angle), 0, 0], [0, 0, 1, 0], [0, 0, 0, 1]]
    end
    point_matrix = [[point[0]], [point[1]], [point[2]], [1]]
    transformed_point = matrix_multiply(rotation_matrix, point_matrix)
    return [transformed_point[0][0], transformed_point[1][0], transformed_point[2][0]]
end

def scale_point(point, scale)
    scaling_matrix = [[scale, 0, 0, 0], [0, scale, 0, 0], [0, 0, scale, 0], [0, 0, 0, 1]]
    point_matrix = [[point[0]], [point[1]], [point[2]], [1]]
    transformed_point = matrix_multiply(scaling_matrix, point_matrix)
    return [transformed_point[0][0], transformed_point[1][0], transformed_point[2][0]]
end

def main()
    point = [1, 2, 3]
    translation = [1, 1, 1]
    angle = 30 * (3.14159 / 180)
    scale_factor = 2
    point = translate_point(point, translation)
    point = rotate_point(point, angle, 'z')
    point = scale_point(point, scale_factor)
    puts point
end

main()