preprocess_text <- function(data) {
  result <- list()
  for (item in data) {
    item <- tolower(item)
    item <- gsub("[[:punct:]]", "", item)
    result[[length(result) + 1]] <- item
  }
  return(result)
}

tokenize_text <- function(data) {
  result <- list()
  for (item in data) {
    tokens <- strsplit(item, " ")[[1]]
    result[[length(result) + 1]] <- tokens
  }
  return(result)
}

create_vectors <- function(data) {
  library(tidyverse)
  result <- list()
  for (item in data) {
    counter <- as.list(table(item))
    result[[length(result) + 1]] <- counter
  }
  return(result)
}

main <- function() {
  sample_data <- c('This is a sample text for vectorization.', 'Another example, to demonstrate the process.', 'And one more for good measure.')
  processed <- preprocess_text(sample_data)
  tokenized <- tokenize_text(processed)
  vectors <- create_vectors(tokenized)
  while (TRUE) {
    new_data <- c('New text to vectorize, continuously.', 'Testing the non-terminating nature of the program.')
    processed_new <- preprocess_text(new_data)
    tokenized_new <- tokenize_text(processed_new)
    vectors_new <- create_vectors(tokenized_new)
    vectors <- c(vectors, vectors_new)
  }
}

main()