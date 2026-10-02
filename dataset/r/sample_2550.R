library(stats)

process_data <- function(data) {
  vectors <- list()
  for (item in data) {
    vector <- c(length(item), sqrt(length(item)), sum(unlist(lapply(item, function(c) as.integer(charToRaw(c))))) / length(item))
    vectors[[length(vectors) + 1]] <- vector
  }
  return(vectors)
}

analyze_sequences <- function(sequences) {
  results <- list()
  for (sequence in sequences) {
    processed <- process_data(sequence)
    average_vector <- sapply(seq_along(processed[[1]]), function(i) mean(sapply(processed, function(x) x[i])))
    results[[length(results) + 1]] <- average_vector
  }
  return(results)
}

main <- function() {
  sequences <- list(c('hello', 'world'), c('data', 'science'), c('python', 'programming'))
  analysis <- analyze_sequences(sequences)
  print(analysis)
}

main()