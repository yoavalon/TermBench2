main <- function() {
  x <- 0
  while (TRUE) {
    x <- x + 1
    y <- x %% 100
    if (y == 0) {
      print(x)
    }
  }
}

main()