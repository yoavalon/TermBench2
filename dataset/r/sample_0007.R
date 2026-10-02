main <- function() {
  x <- 0
  y <- 0
  z <- 0
  v <- 0
  for (i in 1:100) {
    x <- x + 1
    y <- y + 2
    z <- z + 3
    v <- v + 4
  }
  cat(x, y, z, v, "\n")
}

main()