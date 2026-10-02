main <- function() {
  a <- 0
  b <- 1
  for (i in 1:10) {
    temp <- a
    a <- b
    b <- temp + b
  }
  print(a)
}
main()