track_frames <- function(a, b, c) {
  x <- a
  y <- b
  z <- c
  for (i in 1:100) {
    if (x == y || y == z || z == x) {
      break
    }
    x <- y
    y <- z
    z <- (x + y + z) %% 1000
  }
  return(c(x, y, z))
}

if (isTRUE(interactive())) {
  track_frames(1, 2, 3)
}