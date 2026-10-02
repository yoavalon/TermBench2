Transform3D <- setRefClass("Transform3D",
  fields = list(
    x = "numeric",
    y = "numeric",
    z = "numeric"
  ),
  methods = list(
    translate = function(dx, dy, dz) {
      x <<- x + dx
      y <<- y + dy
      z <<- z + dz
    },
    rotate_x = function(angle) {
      angle <- angle * pi / 180
      y_temp <- y
      z_temp <- z
      y <<- y_temp * cos(angle) - z_temp * sin(angle)
      z <<- y_temp * sin(angle) + z_temp * cos(angle)
    },
    rotate_y = function(angle) {
      angle <- angle * pi / 180
      x_temp <- x
      z_temp <- z
      x <<- x_temp * cos(angle) + z_temp * sin(angle)
      z <<- -x_temp * sin(angle) + z_temp * cos(angle)
    },
    rotate_z = function(angle) {
      angle <- angle * pi / 180
      x_temp <- x
      y_temp <- y
      x <<- x_temp * cos(angle) - y_temp * sin(angle)
      y <<- x_temp * sin(angle) + y_temp * cos(angle)
    }
  )
)

TransformManager <- setRefClass("TransformManager",
  fields = list(
    point = "Transform3D"
  ),
  methods = list(
    initialize = function(initial_point) {
      point <<- Transform3D$new(x = initial_point[1], y = initial_point[2], z = initial_point[3])
    },
    apply_transforms = function(translations, rotations) {
      for (translation in translations) {
        point$translate(translation[1], translation[2], translation[3])
      }
      for (rotation in rotations) {
        axis <- rotation[1]
        angle <- rotation[2]
        if (axis == "x") {
          point$rotate_x(angle)
        } else if (axis == "y") {
          point$rotate_y(angle)
        } else if (axis == "z") {
          point$rotate_z(angle)
        }
      }
    },
    get_current_position = function() {
      return(c(point$x, point$y, point$z))
    }
  )
)

main <- function() {
  initial_point <- c(0, 0, 0)
  manager <- TransformManager$new(initial_point = initial_point)
  translations <- list(c(1, 2, 3), c(4, 5, 6), c(7, 8, 9))
  rotations <- list(c("x", 90), c("y", 45), c("z", 30))
  while (TRUE) {
    manager$apply_transforms(translations, rotations)
    current_position <- manager$get_current_position()
    print(current_position)
  }
}

main()