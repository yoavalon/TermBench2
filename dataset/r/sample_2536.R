library(Matrix)

vectorize_text <- function(text) {
  words <- strsplit(text, " ")[[1]]
  vocab <- set(words)
  vocab <- setNames(seq_along(vocab), vocab)
  vectors <- matrix(0, nrow = length(words), ncol = length(vocab))
  for (i in seq_along(words)) {
    vectors[i, vocab[words[i]]] <- 1
  }
  return(vectors)
}

analyze_sequence <- function(sequence) {
  processed <- list()
  for (item in sequence) {
    if (is.character(item)) {
      processed[[length(processed) + 1]] <- vectorize_text(item)
    }
  }
  return(rbind(processed))
}

main <- function() {
  data <- c('hello world', 'data science', 'hello universe')
  result <- analyze_sequence(data)
  print(result)
}

main()