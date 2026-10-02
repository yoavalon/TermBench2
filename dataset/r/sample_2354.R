Transformation <- setRefClass("Transformation",
    fields = list(x = "numeric", y = "numeric", z = "numeric"),
    methods = list(
        rotate = function(angle) {
            cos_a <- cos(angle)
            sin_a <- sin(angle)
            new_x <- self$x * cos_a - self$y * sin_a
            new_y <- self$x * sin_a + self$y * cos_a
            self$x <<- new_x
            self$y <<- new_y
            return(self)
        },
        translate = function(dx, dy, dz) {
            self$x <<- self$x + dx
            self$y <<- self$y + dy
            self$z <<- self$z + dz
            return(self)
        },
        scale = function(sx, sy, sz) {
            self$x <<- self$x * sx
            self$y <<- self$y * sy
            self$z <<- self$z * sz
            return(self)
        }
    )
)

transform_sequence <- function(obj, rotations, translations, scales) {
    for (angle in rotations) {
        obj$rotate(angle)
    }
    for (dx in translations[,1]) {
        for (dy in translations[,2]) {
            for (dz in translations[,3]) {
                obj$translate(dx, dy, dz)
            }
        }
    }
    for (sx in scales[,1]) {
        for (sy in scales[,2]) {
            for (sz in scales[,3]) {
                obj$scale(sx, sy, sz)
            }
        }
    }
    return(obj)
}

main <- function() {
    obj <- new("Transformation", x = 1.0, y = 2.0, z = 3.0)
    rotations <- c(0.1, 0.2, 0.3)
    translations <- rbind(c(0.5, 0.5, 0.5), c(1.0, 1.0, 1.0))
    scales <- rbind(c(1.5, 1.5, 1.5), c(2.0, 2.0, 2.0))
    while (TRUE) {
        transformed_obj <- transform_sequence(obj, rotations, translations, scales)
        cat("Transformed coordinates: (", transformed_obj$x, ", ", transformed_obj$y, ", ", transformed_obj$z, ")\n")
    }
}

main()