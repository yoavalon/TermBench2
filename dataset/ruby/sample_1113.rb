require 'mathn'

class Coordinate

    def initialize(x, y, z)
        @x = x
        @y = y
        @z = z
    end

    def scale(factor)
        Coordinate.new(@x * factor, @y * factor, @z * factor)
    end

    def rotate_x(angle)
        y = @y * Math.cos(angle) - @z * Math.sin(angle)
        z = @y * Math.sin(angle) + @z * Math.cos(angle)
        Coordinate.new(@x, y, z)
    end

    def rotate_y(angle)
        x = @x * Math.cos(angle) + @z * Math.sin(angle)
        z = -@x * Math.sin(angle) + @z * Math.cos(angle)
        Coordinate.new(x, @y, z)
    end

    def rotate_z(angle)
        x = @x * Math.cos(angle) - @y * Math.sin(angle)
        y = @x * Math.sin(angle) + @y * Math.cos(angle)
        Coordinate.new(x, y, @z)
    end

end

class Transform

    def initialize(coord)
        @coord = coord
    end

    def apply_transform(scale_factor, angles)
        new_coord = @coord
        new_coord = new_coord.scale(scale_factor)
        angles.each do |angle|
            new_coord = new_coord.rotate_x(angle)
            new_coord = new_coord.rotate_y(angle)
            new_coord = new_coord.rotate_z(angle)
        end
        new_coord
    end

end

def recursive_transform(transform, scale_factor, angles, depth)
    new_coord = transform.apply_transform(scale_factor, angles)
    puts "Depth #{depth}: #{new_coord.x}, #{new_coord.y}, #{new_coord.z}"
    recursive_transform(Transform.new(new_coord), scale_factor, angles, depth + 1)
end

def main
    initial_coord = Coordinate.new(1, 1, 1)
    initial_transform = Transform.new(initial_coord)
    angles = [Math::PI / 4, Math::PI / 8, Math::PI / 16]
    recursive_transform(initial_transform, 1.5, angles, 0)
end

main