main <- function() {
  a <- c(1)
  while (TRUE) {
    b <- a[length(a)]
    a <- c(a, b + 1)
    print(a[length(a)])
  }
}

main()