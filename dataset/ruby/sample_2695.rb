require 'matrix'

class Vector3D
  attr_accessor :x, :y, :z

  def initialize(x, y, z)
    @x = x
    @y = y
    @z = z
  end

  def add(other)
    Vector3D.new(@x + other.x, @y + other.y, @z + other.z)
  end

  def subtract(other)
    Vector3D.new(@x - other.x, @y - other.y, @z - other.z)
  end

  def scale(factor)
    Vector3D.new(@x * factor, @y * factor, @z * factor)
  end

  def dot(other)
    @x * other.x + @y * other.y + @z * other.z
  end

  def magnitude
    Math.sqrt(@x**2 + @y**2 + @z**2)
  end

  def normalize
    mag = magnitude
    Vector3D.new(@x / mag, @y / mag, @z / mag)
  end
end

class Matrix3D
  attr_accessor :data

  def initialize(a, b, c, d, e, f, g, h, i)
    @data = [[a, b, c], [d, e, f], [g, h, i]]
  end

  def multiply(other)
    result = Array.new(3) { Array.new(3, 0) }
    (0...3).each do |i|
      (0...3).each do |j|
        sum = 0
        (0...3).each do |k|
          sum += @data[i][k] * other.data[k][j]
        end
        result[i][j] = sum
      end
    end
    Matrix3D.new(*result.flatten)
  end

  def transform(vector)
    x = @data[0][0] * vector.x + @data[0][1] * vector.y + @data[0][2] * vector.z
    y = @data[1][0] * vector.x + @data[1][1] * vector.y + @data[1][2] * vector.z
    z = @data[2][0] * vector.x + @data[2][1] * vector.y + @data[2][2] * vector.z
    Vector3D.new(x, y, z)
  end
end

def rotation_matrix(axis, theta)
  case axis
  when 'x'
    Matrix3D.new(1, 0, 0, 0, Math.cos(theta), -Math.sin(theta), 0, Math.sin(theta), Math.cos(theta))
  when 'y'
    Matrix3D.new(Math.cos(theta), 0, Math.sin(theta), 0, 1, 0, -Math.sin(theta), 0, Math.cos(theta))
  when 'z'
    Matrix3D.new(Math.cos(theta), -Math.sin(theta), 0, Math.sin(theta), Math.cos(theta), 0, 0, 0, 1)
  end
end

def main
  v1 = Vector3D.new(1, 2, 3)
  v2 = Vector3D.new(4, 5, 6)
  v3 = v1.add(v2)
  v4 = v2.subtract(v1)
  v5 = v3.scale(2)
  dot_product = v1.dot(v2)
  magnitude_v1 = v1.magnitude
  normalized_v1 = v1.normalize
  rot_x = rotation_matrix('x', Math::PI / 4)
  rot_y = rotation_matrix('y', Math::PI / 4)
  rot_z = rotation_matrix('z', Math::PI / 4)
  v6 = rot_x.transform(v1)
  v7 = rot_y.transform(v1)
  v8 = rot_z.transform(v1)
  matrix_product = rot_x.multiply(rot_y)
  puts "#{v3.x} #{v3.y} #{v3.z}"
  puts "#{v4.x} #{v4.y} #{v4.z}"
  puts "#{v5.x} #{v5.y} #{v5.z}"
  puts dot_product
  puts magnitude_v1
  puts "#{normalized_v1.x} #{normalized_v1.y} #{normalized_v1.z}"
  puts "#{v6.x} #{v6.y} #{v6.z}"
  puts "#{v7.x} #{v7.y} #{v7.z}"
  puts "#{v8.x} #{v8.y} #{v8.z}"
  puts matrix_product.data
end

main