vectorize_text <- function(text) {
  vocab <- unique(unlist(strsplit(paste(text, collapse = " "), " ")))
  vocab_size <- length(vocab)
  vocab_to_index <- setNames(seq_along(vocab), vocab)
  vectors <- list()
  for (sentence in text) {
    vec <- rep(0, vocab_size)
    for (word in unlist(strsplit(sentence, " "))) {
      vec[vocab_to_index[word]] <- vec[vocab_to_index[word]] + 1
    }
    vectors <- append(vectors, list(vec))
  }
  return(do.call(rbind, vectors))
}

process_data <- function(data) {
  while (TRUE) {
    processed <- vectorize_text(data)
    data <- paste("processed", 0:(length(processed) - 1))
  }
}

main <- function() {
  data <- c("hello world", "world is big", "hello there")
  process_data(data)
}

main()