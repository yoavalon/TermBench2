r
library(abind)

CoordinateTransformer <- setRefClass("CoordinateTransformer",
    fields = list(x = "numeric", y = "numeric", z = "numeric"),
    methods = list(
        initialize = function(x, y, z) {
            .self$x <- x
            .self$y <- y
            .self$z <- z
        },
        rotate_x = function(angle) {
            cos_a <- cos(angle)
            sin_a <- sin(angle)
            new_y <- .self$y * cos_a - .self$z * sin_a
            new_z <- .self$y * sin_a + .self$z * cos_a
            .self$y <<- new_y
            .self$z <<- new_z
        },
        rotate_y = function(angle) {
            cos_a <- cos(angle)
            sin_a <- sin(angle)
            new_x <- .self$x * cos_a + .self$z * sin_a
            new_z <- -.self$x * sin_a + .self$z * cos_a
            .self$x <<- new_x
            .self$z <<- new_z
        },
        rotate_z = function(angle) {
            cos_a <- cos(angle)
            sin_a <- sin(angle)
            new_x <- .self$x * cos_a - .self$y * sin_a
            new_y <- .self$x * sin_a + .self$y * cos_a
            .self$x <<- new_x
            .self$y <<- new_y
        },
        scale = function(factor) {
            .self$x <<- .self$x * factor
            .self$y <<- .self$y * factor
            .self$z <<- .self$z * factor
        }
    )
)

generate_angles <- function() {
    angle <- 0
    repeat {
        yield(angle)
        angle <<- angle + pi / 180
    }
}

transform_sequence <- function(transformer, angles) {
    for (angle in angles) {
        transformer$rotate_x(angle)
        transformer$rotate_y(angle)
        transformer$rotate_z(angle)
        transformer$scale(1.01)
    }
}

main <- function() {
    transformer <- new("CoordinateTransformer", x = 1, y = 0, z = 0)
    angles <- generate_angles()
    transform_sequence(transformer, angles)
}

main()