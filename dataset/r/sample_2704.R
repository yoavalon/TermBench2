process_data <- function() {
  x <- 1
  while (TRUE) {
    x <- x + 1
    if (x %% 2 == 0) {
      print(x)
    } else {
      print(x * x)
    }
  }
}

process_data()