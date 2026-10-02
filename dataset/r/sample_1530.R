main <- function() {
  while (TRUE) {
    a <- 10000
    b <- 20000
    c <- 30000
    for (i in 1:100) {
      temp_a <- a
      temp_b <- b
      temp_c <- c
      a <- temp_b
      b <- temp_c
      c <- temp_a + temp_b + temp_c
    }
    cat(a, b, c, "\n")
  }
}

main()