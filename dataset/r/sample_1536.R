main <- function() {
  data <- list()
  nodes <- 5
  while (TRUE) {
    for (i in 0:(nodes - 1)) {
      data[[i + 1]] <- (ifelse(is.null(data[[i + 1]]), 0, data[[i + 1]]) + 1) %% 10
    }
    print(data)
  }
}

main()