f <- function(g, h) {
  f(h, g + h)
}

main <- function() {
  a <- 0
  b <- 1
  f(a, b)
}

main()