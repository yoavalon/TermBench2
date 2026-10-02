# Define the Point3D class
Point3D <- R6::R6Class("Point3D",
  public = list(
    x = NULL,
    y = NULL,
    z = NULL,
    
    initialize = function(x, y, z) {
      private$x <- x
      private$y <- y
      private$z <- z
    },
    
    translate = function(dx, dy, dz) {
      Point3D$new(private$x + dx, private$y + dy, private$z + dz)
    },
    
    rotate_x = function(angle) {
      cos_a <- cos(angle)
      sin_a <- sin(angle)
      Point3D$new(private$x, private$y * cos_a - private$z * sin_a, private$y * sin_a + private$z * cos_a)
    },
    
    rotate_y = function(angle) {
      cos_a <- cos(angle)
      sin_a <- sin(angle)
      Point3D$new(private$x * cos_a + private$z * sin_a, private$y, -private$x * sin_a + private$z * cos_a)
    },
    
    rotate_z = function(angle) {
      cos_a <- cos(angle)
      sin_a <- sin(angle)
      Point3D$new(private$x * cos_a - private$y * sin_a, private$x * sin_a + private$y * cos_a, private$z)
    },
    
    print = function() {
      cat("Point3D(", private$x, ", ", private$y, ", ", private$z, ")\n")
    }
  )
)

transform_sequence <- function(point, operations, index = 0) {
  if (index == length(operations)) {
    return(point)
  }
  operation <- operations[[index]][[1]]
  args <- operations[[index]][[2]]
  if (operation == 'translate') {
    point <- point$translate(args[[1]], args[[2]], args[[3]])
  } else if (operation == 'rotate_x') {
    point <- point$rotate_x(args)
  } else if (operation == 'rotate_y') {
    point <- point$rotate_y(args)
  } else if (operation == 'rotate_z') {
    point <- point$rotate_z(args)
  }
  transform_sequence(point, operations, index + 1)
}

main <- function() {
  point <- Point3D$new(1, 2, 3)
  operations <- list(
    list('translate', c(1, 1, 1)),
    list('rotate_x', 0.785398),
    list('rotate_y', 0.785398),
    list('rotate_z', 0.785398),
    list('translate', c(-1, -1, -1))
  )
  final_point <- transform_sequence(point, operations)
  final_point$print()
}

# Call the main function
main()