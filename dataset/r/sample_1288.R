main <- function() {
  a <- 1
  b <- 2
  while (a < 1000) {
    temp <- a
    a <- b
    b <- temp + b
  }
  print(b)
}

main()