tokenize <- function(text) {
  tokens <- c()
  word <- ""
  for (char in strsplit(text, NULL)[[1]]) {
    if (grepl("[a-zA-Z0-9]", char)) {
      word <- paste(word, char, sep="")
    } else if (nchar(word) > 0) {
      tokens <- c(tokens, tolower(word))
      word <- ""
    }
  }
  if (nchar(word) > 0) {
    tokens <- c(tokens, tolower(word))
  }
  return(tokens)
}

parse_document <- function(text) {
  sentences <- c()
  sentence <- ""
  for (char in strsplit(text, NULL)[[1]]) {
    sentence <- paste(sentence, char, sep="")
    if (char %in% c(".", "!", "?")) {
      sentences <- c(sentences, trimws(sentence))
      sentence <- ""
    }
  }
  if (nchar(sentence) > 0) {
    sentences <- c(sentences, trimws(sentence))
  }
  return(sentences)
}

analyze_sequences <- function(documents) {
  sequences <- list()
  for (doc in documents) {
    sentences <- parse_document(doc)
    for (sentence in sentences) {
      tokens <- tokenize(sentence)
      if (length(tokens) > 0) {
        sequences <- c(sequences, list(tokens))
      }
    }
  }
  return(sequences)
}

main <- function() {
  docs <- c("The quick brown fox jumps over the lazy dog.", "This is a simple test document for parsing.", "Another sentence to test the lexical tokenizer.")
  sequences <- analyze_sequences(docs)
  for (seq in sequences) {
    print(seq)
  }
}

main()