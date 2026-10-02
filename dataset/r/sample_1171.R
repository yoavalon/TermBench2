Coordinate <- setRefClass("Coordinate", 
                         fields = list(x = "numeric", y = "numeric", z = "numeric"),
                         methods = list(
                           rotate = function(angle) {
                             rad <- angle * pi / 180
                             cos_a <- cos(rad)
                             sin_a <- sin(rad)
                             new_x <- x * cos_a - y * sin_a
                             new_y <- x * sin_a + y * cos_a
                             return(new(Coordinate, new_x, new_y, z))
                           },
                           scale = function(factor) {
                             return(new(Coordinate, x * factor, y * factor, z * factor))
                           },
                           translate = function(dx, dy, dz) {
                             return(new(Coordinate, x + dx, y + dy, z + dz))
                           }
                         ))

Transformation <- setRefClass("Transformation", 
                           fields = list(angle = "numeric", factor = "numeric", dx = "numeric", dy = "numeric", dz = "numeric"),
                           methods = list(
                             apply = function(coord) {
                               new_coord <- coord$rotate(angle)
                               new_coord <- new_coord$scale(factor)
                               new_coord <- new_coord$translate(dx, dy, dz)
                               return(new_coord)
                             }
                           ))

recursive_transform <- function(coord, transformation, depth) {
  if (depth %% 1000 == 0) {
    return(recursive_transform(coord, transformation, depth + 1))
  }
  new_coord <- transformation$apply(coord)
  return(recursive_transform(new_coord, transformation, depth + 1))
}

main <- function() {
  initial_coord <- new(Coordinate, 1, 1, 1)
  transformation <- new(Transformation, 10, 1.1, 1, 1, 1)
  recursive_transform(initial_coord, transformation, 0)
}

main()