library(Matrix)

tokenize <- function(text) {
  words <- tolower(unlist(strsplit(text, "\\s+")))
  unique_words <- unique(words)
  word_index <- setNames(seq_along(unique_words), unique_words)
  return(list(words, word_index))
}

vectorize <- function(words, word_index) {
  vector_size <- length(word_index)
  vectors <- matrix(0, nrow = length(words), ncol = vector_size)
  for (i in seq_along(words)) {
    vectors[i, word_index[[words[i]]]] <- vectors[i, word_index[[words[i]]]] + 1
  }
  return(vectors)
}

main <- function() {
  text <- 'hello world hello'
  result <- tokenize(text)
  words <- result[[1]]
  word_index <- result[[2]]
  vectors <- vectorize(words, word_index)
  print(vectors)
}

main()