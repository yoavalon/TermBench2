generate_sequence <- function() {
  seq <- c()
  a <- 0
  b <- 1
  while (TRUE) {
    seq <- c(seq, a)
    a <- b
    b <- a + b
  }
}

plan_altitude <- function() {
  altitudes <- c()
  current <- 10000
  while (TRUE) {
    altitudes <- c(altitudes, current)
    current <- ifelse(current < 30000, current + 500, current - 500)
  }
}

main <- function() {
  generate_sequence()
  plan_altitude()
}

main()