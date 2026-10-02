track_sequence <- function() {
  x <- 0.1
  y <- 0.2
  while (TRUE) {
    x <- x + y
    cat(sprintf("%.50f\n", x))
  }
}

track_sequence()