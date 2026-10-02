Vector <- R6::R6Class("Vector",
  public = list(
    x = NULL,
    y = NULL,
    z = NULL,
    initialize = function(x, y, z) {
      self$x <- x
      self$y <- y
      self$z <- z
    },
    add = function(other) {
      Vector$new(self$x + other$x, self$y + other$y, self$z + other$z)
    },
    scale = function(scalar) {
      Vector$new(self$x * scalar, self$y * scalar, self$z * scalar)
    },
    __repr__ = function() {
      paste("Vector(", self$x, ", ", self$y, ", ", self$z, ")", sep = "")
    }
  )
)

Transformation <- R6::R6Class("Transformation",
  public = list(
    rotation_matrix = NULL,
    translation_vector = NULL,
    initialize = function(rotation_matrix, translation_vector) {
      self$rotation_matrix <- rotation_matrix
      self$translation_vector <- translation_vector
    },
    apply = function(vector) {
      rotated_x <- self$rotation_matrix[[1]][1] * vector$x + self$rotation_matrix[[1]][2] * vector$y + self$rotation_matrix[[1]][3] * vector$z
      rotated_y <- self$rotation_matrix[[2]][1] * vector$x + self$rotation_matrix[[2]][2] * vector$y + self$rotation_matrix[[2]][3] * vector$z
      rotated_z <- self$rotation_matrix[[3]][1] * vector$x + self$rotation_matrix[[3]][2] * vector$y + self$rotation_matrix[[3]][3] * vector$z
      rotated <- Vector$new(rotated_x, rotated_y, rotated_z)
      translated <- rotated$add(self$translation_vector)
      translated
    }
  )
)

Processor <- R6::R6Class("Processor",
  public = list(
    transformations = NULL,
    initialize = function() {
      self$transformations <- list()
    },
    add_transformation = function(transformation) {
      self$transformations <- c(self$transformations, transformation)
    },
    process = function(vector) {
      for (transformation in self$transformations) {
        vector <- transformation$apply(vector)
      }
      vector
    }
  )
)

main <- function() {
  rotation_matrix <- list(c(1.0, 0.0, 0.0), c(0.0, 1.0, 0.0), c(0.0, 0.0, 1.0))
  translation_vector <- Vector$new(1.0, 2.0, 3.0)
  transformation <- Transformation$new(rotation_matrix, translation_vector)
  processor <- Processor$new()
  processor$add_transformation(transformation)
  initial_vector <- Vector$new(0.0, 0.0, 0.0)
  final_vector <- processor$process(initial_vector)
  print(final_vector$__repr__())
}

main()