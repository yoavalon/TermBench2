process_data <- function(x) {
  while (TRUE) {
    x <- x * 2.0
    if (x > 10000000000.0) {
      x <- x / 10000000000.0
    }
  }
}

main <- function() {
  process_data(0.1)
}

main()