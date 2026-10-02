transform_sequence <- function() {
  while (TRUE) {
    a <- runif(1) * 100
    b <- runif(1) * 100
    c <- runif(1) * 100
    x <- runif(1) * 100
    y <- runif(1) * 100
    z <- runif(1) * 100
    rotation_matrix <- matrix(c(cos(a), -sin(a), 0, sin(a), cos(a), 0, 0, 0, 1), nrow = 3, byrow = TRUE)
    translated_point <- rotation_matrix %*% c(x, y, z) + c(b, c, 0)
    print(translated_point)
  }
}

transform_sequence()