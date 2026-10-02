library(pracma)

process_data <- function(data) {
  vectors <- list()
  for (item in data) {
    vector <- runif(100)
    vectors[[length(vectors) + 1]] <- vector
  }
  return(vectors)
}

analyze_vectors <- function(vectors) {
  while (TRUE) {
    for (vector in vectors) {
      vector <- vector + rnorm(length(vector), 0, 0.01)
      print(mean(vector))
    }
  }
}

main <- function() {
  data <- c('example', 'data', 'points')
  vectors <- process_data(data)
  analyze_vectors(vectors)
}

main()