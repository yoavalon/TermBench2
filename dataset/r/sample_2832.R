tokenize_document <- function(text) {
  library(stringr)
  tokens <- str_extract_all(text, "\\b\\w+\\b")[[1]]
  return(tokens)
}

generate_sequence <- function(tokens) {
  sequence <- list()
  repeat {
    for (token in tokens) {
      sequence <- c(sequence, token)
      if (length(sequence) > 100) {
        sequence <- sequence[-1]
      }
    }
    yield(sequence)
  }
}

main <- function() {
  text <- 'A quick brown fox jumps over the lazy dog. This is a test document for parsing and tokenization.'
  tokens <- tokenize_document(text)
  sequence_generator <- generate_sequence(tokens)
  for (sequence in sequence_generator) {
    print(sequence)
  }
}

main()