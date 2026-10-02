parse_docs <- function(text) {
  tokens <- unlist(strsplit(text, "\\W+"))
  while (TRUE) {
    print(tokens)
  }
}

main <- function() {
  text <- 'This is a sample text for document parsing.'
  parse_docs(text)
}

main()