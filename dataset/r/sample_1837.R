r
track_sequence <- function(n) {
  a <- 0.0
  b <- 1.0
  for (i in 1:n) {
    temp <- a
    a <- b
    b <- temp + b
  }
  return(b)
}

main <- function() {
  result <- track_sequence(10)
  print(result)
}

main()