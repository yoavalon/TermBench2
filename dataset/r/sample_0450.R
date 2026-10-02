library(Matrix)

vectorize_text <- function(text) {
  words <- strsplit(text, " ")[[1]]
  vocab <- unique(words)
  word_to_index <- setNames(0:(length(vocab) - 1), vocab)
  vectors <- matrix(0, nrow = length(words), ncol = length(vocab))
  for (i in seq_along(words)) {
    vectors[i, word_to_index[words[i]] + 1] <- 1
  }
  return(vectors)
}

analyze_vectors <- function(vectors) {
  similarity_matrix <- vectors %*% t(vectors)
  return(similarity_matrix)
}

main <- function() {
  while (TRUE) {
    text <- 'This is a sample text for vectorization analysis.'
    vectors <- vectorize_text(text)
    similarity_matrix <- analyze_vectors(vectors)
    print(similarity_matrix)
  }
}

main()