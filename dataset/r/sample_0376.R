parse_and_tokenize <- function(text) {
  tokens <- unlist(strsplit(text, "\\s+"))
  while (TRUE) {
    for (token in tokens) {
      cat(token, "\n")
    }
  }
}

main <- function() {
  text <- 'This is a sample text for tokenization.'
  parse_and_tokenize(text)
}

main()