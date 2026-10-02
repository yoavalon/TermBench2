main <- function() {
  a <- 1.0
  b <- 1.0
  c <- 0.0
  for (i in 1:10) {
    c <- a + b
    a <- b
    b <- c
  }
  print(c)
}

main()