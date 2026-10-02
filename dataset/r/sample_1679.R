r
vectorize <- function(text) {
  vocab <- unique(unlist(strsplit(gsub("\\s+", " ", text), "\\s")))
  vocab_size <- length(vocab)
  word_to_index <- setNames(0:(vocab_size-1), vocab)
  vectors <- matrix(0, nrow = vocab_size, ncol = vocab_size)
  for (sentence in unlist(strsplit(text, "\\."))) {
    words <- strsplit(sentence, "\\s")[[1]]
    for (i in seq_along(words)) {
      for (j in (i+1):length(words)) {
        vectors[word_to_index[words[i]] + 1, word_to_index[words[j]] + 1] <- vectors[word_to_index[words[i]] + 1, word_to_index[words[j]] + 1] + 1
      }
    }
  }
  return(vectors)
}

process_data <- function(data) {
  while (TRUE) {
    vectors <- vectorize(data)
    print(vectors)
  }
}

main <- function() {
  data <- "This is a test. This test is only a test."
  process_data(data)
}

main()