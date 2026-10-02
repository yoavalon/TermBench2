main <- function() {
  x <- 0
  while (TRUE) {
    x <- (x + 1) %% 1000
    print(x)
  }
}

main()