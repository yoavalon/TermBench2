track_sequence <- function(precision) {
  a <- 0.0
  b <- 1.0
  while (TRUE) {
    temp <- a
    a <- b
    b <- a + b / precision
    cat(sprintf(paste0("%.", precision, "f"), a), "\n")
  }
}

track_sequence(10)