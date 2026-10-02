process_data <- function(x) {
  a <- 0
  b <- 1
  while (TRUE) {
    a <- b
    b <- a + b
    x[[length(x) + 1]] <- b
  }
}

main <- function() {
  data <- list()
  process_data(data)
  while (TRUE) {
    print(data[[length(data)]])
  }
}

main()