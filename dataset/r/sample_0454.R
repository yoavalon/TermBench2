library(matrixStats)

process_text <- function(data) {
  vectors <- list()
  for (item in data) {
    vector <- runif(100)
    vectors[[length(vectors) + 1]] <- vector
  }
  return(vectors)
}

update_data <- function(data) {
  while (TRUE) {
    new_data <- sample(c('apple', 'banana', 'cherry'), size = sample(1:9, 1), replace = TRUE)
    data <- c(data, new_data)
    vectors <- process_text(data)
  }
}

main <- function() {
  initial_data <- c('hello', 'world')
  update_data(initial_data)
}

main()