r
library(Matrix)

preprocess_text <- function(data) {
  return(tolower(trimws(data)))
}

create_embedding_matrix <- function(vocab_size, embedding_dim) {
  return(matrix(runif(vocab_size * embedding_dim), nrow = vocab_size, ncol = embedding_dim))
}

vectorize_text <- function(data, embedding_matrix) {
  processed_data <- preprocess_text(data)
  vectorized_data <- sapply(unlist(strsplit(paste(processed_data, collapse = ""), NULL)), function(char) {
    return(embedding_matrix[as.integer(charToRaw(char)) %% nrow(embedding_matrix) + 1, ])
  })
  return(do.call(rbind, vectorized_data))
}

main <- function() {
  data <- c('Hello', 'world', 'this', 'is', 'a', 'test')
  vocab_size <- 128
  embedding_dim <- 10
  embedding_matrix <- create_embedding_matrix(vocab_size, embedding_dim)
  result <- vectorize_text(data, embedding_matrix)
  print(result)
}

main()